#include "student_code.h"
#include "mutablePriorityQueue.h"

using namespace std;

namespace CGL
{

  // Vector2D interpolate(Vector2D a, Vector2D b, float t){

  //   //float t = t;   
  //   return a * (1.0f - t) + b * t;
  // }

  void BezierCurve::evaluateStep(){
    // TODO Part 1.
    // Perform one step of the Bezier curve's evaluation at t using de Casteljau's algorithm for subdivision.
    // Store all of the intermediate control points into the 2D vector evaluatedLevels.

    int size = controlPoints.size();
    Vector2D ab, bc, cd, de, abc, bcd, abcd, bcde, abcde;

    //cubic
    ab = controlPoints[0] * (1.0f - t) + controlPoints[1] * t;
    bc = controlPoints[1] * (1.0f - t) + controlPoints[2] * t;
    cd = controlPoints[2] * (1.0f - t) + controlPoints[3] * t;
    de = controlPoints[3] * (1.0f - t) + controlPoints[4] * t;

    vector <Vector2D> resf = {ab, bc, cd};
    evaluatedLevels.push_back(resf);

    //quartic
    abc = ab * (1.0f - t) + bc * t;
    bcd = bc * (1.0f - t) + cd * t;

    resf = {abc, bcd};
    evaluatedLevels.push_back(resf);

    abcd = ab * (1.0f - t) + bc * t;
    bcde = bc * (1.0f - t) + de * t;

    abcde = abcd * (1.0f - t) + bcde * t;

    resf = {abcde}; 
    evaluatedLevels.push_back(resf);

  } 

  Vector3D BezierPatch::evaluate(double u, double v) const{
    // TODO Part 2.
    // Evaluate the Bezier surface at parameters (u, v) through 2D de Casteljau subdivision.
    // (i.e. Unlike Part 1 where we performed one subdivision level per call to evaluateStep, this function
    // should apply de Casteljau's algorithm until it computes the final, evaluated point on the surface)
    vector <Vector3D> Uvec;
    int size = controlPoints.size();

    for (int i = 0; i < size; i++){
      Vector3D insert = evaluate1D(controlPoints[i], u);
      Uvec.push_back(insert);
    }

    return evaluate1D(Uvec, v);
  }

  Vector3D BezierPatch::evaluate1D(std::vector<Vector3D> points, double t) const
  {
    // TODO Part 2.
    // Optional helper function that you might find useful to implement as an abstraction when implementing BezierPatch::evaluate.
    // Given an array of 4 points that lie on a single curve, evaluates the Bezier curve at parameter t using 1D de Casteljau subdivision.
    vector <Vector3D> first = points;
    vector <Vector3D> sec = points;
    int size_sec = sec.size();

    while(size_sec > 1 ){

      sec.clear();
      for(int i = 0; i < first.size()-1; i++){
        Vector3D result = (1.0f - t) * first[i] + t * first[i + 1];
        sec.push_back(result);
      }

      first = sec;
      size_sec = sec.size();
    }

    return sec[0];
  }

  Vector3D Vertex::normal( void ) const
  {
    // TODO Part 3.
    // TODO Returns an approximate unit normal at this vertex, computed by
    // TODO taking the area-weighted average of the normals of neighboring
    // TODO triangles, then normalizing.
    Vector3D n(0,0,0);
    HalfedgeCIter h = halfedge();
    h = h->twin();

    HalfedgeCIter h_orig = h;

    do{
      Vector3D v1 = h->vertex()->position;
      h = h->next();

      Vector3D v2 = h->vertex()->position;
      h = h->twin();

      Vector3D v3 = h->vertex()->position;

      n += cross(v2-v1, v3 - v1);
    } while(h != h_orig);

    return n.unit();
  }

  EdgeIter HalfedgeMesh::flipEdge( EdgeIter e0 )
  {
    // TODO Part 4.
    // TODO This method should flip the given edge and return an iterator to the flipped edge.

    if(e0->isBoundary()){
      return e0;
    }

    HalfedgeIter ha = e0->halfedge();
    HalfedgeIter ta = ha->twin();

    HalfedgeIter hb = ha->next();
    HalfedgeIter tb = ta->next();

    HalfedgeIter hc = hb->next();
    HalfedgeIter tc = tb->next();

    VertexIter v0 = hb->vertex();
    VertexIter v1 = tb->vertex();
    VertexIter v2 = hc->vertex();
    VertexIter v3 = tc->vertex();

    FaceIter f1 = ha->face();
    FaceIter f2 = ta->face();

    ha->setNeighbors(tc,ta,v3,ha->edge(),f1);
    hb->setNeighbors(ha,hb->twin(),v2,hb->edge(),f1);
    hc->setNeighbors(tb,hc->twin(),v1,hc->edge(),f2);
    ta->setNeighbors(hc,ha,v2,ta->edge(),f2);
    tb->setNeighbors(ta,tb->twin(),v3,tb->edge(),f2);
    tc->setNeighbors(hb,tc->twin(),v0,tc->edge(),f1);

    f1->halfedge() = ha;
    f2->halfedge() = ta;

    v0->halfedge() = tb;
    v1->halfedge() = hc;
    v2->halfedge() = hb;
    v3->halfedge() = ta;

    return e0;
  }

  VertexIter HalfedgeMesh::splitEdge( EdgeIter e0 )
{
    // TODO Part 5.
    // TODO This method should split the given edge and return an iterator to the newly inserted vertex.
    // TODO The halfedge of this vertex should point along the edge that was split, rather than the new edges.

    HalfedgeIter ha = e0->halfedge();
    HhealfedgeIter ta = ha->twin();

    HalfedgeIter hb = ha->next();
    HalfedgeIter tb = ta->next();        
    HalfedgeIter hc = hb->next();
    HalfedgeIter tc = tb->next();   

    FaceIter f1 = ha->face();
    FaceIter f2 = ta->face();
    FaceIter f3 = newFace();
    FaceIter f4 = newFace();

    VertexIter v0 = ha->vertex();
    VertexIter v2 = ta->vertex();
    VertexIter v1 = hc->vertex();
    VertexIter v3 = tc->vertex();
    VertexIter v4 = newVertex();

    Vector3D pos = ((v0->position) + (v2->position))/2;
    v4->position = pos;

    HalfedgeIter hd = newHalfedge();
    HalfedgeIter he = newHalfedge();
    HalfedgeIter hf = newHalfedge();
    HalfedgeIter td = newHalfedge();
    HalfedgeIter te = newHalfedge();
    HalfedgeIter tf = newHalfedge();

    EdgeIter e1 = newEdge();
    EdgeIter e2 = newEdge();
    EdgeIter e3 = newEdge();

    ta->setNeighbors(td,hf,v2,e2,f2);
    tb->setNeighbors(te,tb->twin(),v0,tb->edge(),f4);
    tc->setNeighbors(ta,tc->twin(),v3,tc->edge(),f2);        
    td->setNeighbors(tc,te,v4,e3,f2);        
    te->setNeighbors(tf,td,v3,e3,f4);        
    tf->setNeighbors(tb,ha,v4,tf->edge(),f4); 

    ha->setNeighbors(hd,tf,v0,ha->edge(),f1);
    hb->setNeighbors(he,hb->twin(),v2,hb->edge(),f3);
    hc->setNeighbors(ha,hc->twin(),v1,hc->edge(),f1);        
    hd->setNeighbors(hc,he,v4,e1,f1);        
    he->setNeighbors(hf,hd,v1,e1,f3);        
    hf->setNeighbors(hb,ta,v4,e2,f3);

    f1->halfedge() = ha;
    f2->halfedge() = ta;
    f3->halfedge() = he;
    f4->halfedge() = te;

    v0->halfedge() = tb;
    v1->halfedge() = hc;
    v2->halfedge() = hb;
    v3->halfedge() = tc; 
    v4->halfedge() = hf; 

    e0->halfedge() = ha;       
    e1->halfedge() = he;       
    e2->halfedge() = ta;       
    e3->halfedge() = te;       

    return e0->halfedge()->vertex();
  }

  void MeshResampler::upsample( HalfedgeMesh& mesh )
  {
    // TODO Part 6.
    // This routine should increase the number of triangles in the mesh using Loop subdivision.
    // Each vertex and edge of the original surface can be associated with a vertex in the new (subdivided) surface.
    // Therefore, our strategy for computing the subdivided vertex locations is to *first* compute the new positions
    // using the connectity of the original (coarse) mesh; navigating this mesh will be much easier than navigating
    // the new subdivided (fine) mesh, which has more elements to traverse. We will then assign vertex positions in
    // the new mesh based on the values we computed for the original mesh.


    // TODO Compute new positions for all the vertices in the input mesh, using the Loop subdivision rule,
    // TODO and store them in Vertex::newPosition. At this point, we also want to mark each vertex as being
    // TODO a vertex of the original mesh.


    // TODO Next, compute the updated vertex positions associated with edges, and store it in Edge::newPosition.


    // TODO Next, we're going to split every edge in the mesh, in any order.  For future
    // TODO reference, we're also going to store some information about which subdivided
    // TODO edges come from splitting an edge in the original mesh, and which edges are new,
    // TODO by setting the flat Edge::isNew.  Note that in this loop, we only want to iterate
    // TODO over edges of the original mesh---otherwise, we'll end up splitting edges that we
    // TODO just split (and the loop will never end!)


    // TODO Now flip any new edge that connects an old and new vertex.


    // TODO Finally, copy the new vertex positions into final Vertex::position.
  }

}
