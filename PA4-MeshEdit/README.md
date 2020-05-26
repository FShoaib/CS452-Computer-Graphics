# Assignment 4: MeshEdit



<body>



</div>
</div>

<div class="content_container">

<!-- renng: commenting this out; not sure why it's here'
</body>
-->

<!-- end of header -->






<hr size="1">


<div class="markdown article-content">
<p><img src="/uploads/article_images/9_2.jpg" alt="" /></p>

<p>In this assignment you will explore a subset of the geometric topics covered in lecture. You will build Bezier curves and surfaces using de Casteljau's algorithm, manipulate half-edge meshes, implement Loop subdivision, and write shaders for your own meshes! When you are finished, you will have a tool that allows you to load and edit basic COLLADA mesh files that are now used by many major modeling packages and real time graphics engines

<h2>Logistics</h2>

<h3>Deadline</h3>

<p>The deadline for the entire assignment is Tuesday, November 20th at 11:55pm. However, you can avail a 10% bonus if you submit Section 1 by Wednesday, November 14th.</p>

<h3>Before you get started...</h3>

<p>As you go through the assignment, refer to the write-up guidelines and deliverables section at the bottom of this page. It is recommended that you accumulate deliverables into sections in your webpage write-up as you work through the project. Please consult this article on <a href="https://cs184.org/article/7">how to build the assignment</a>.</p>

<h3>Getting started</h3>

<p>You can clone the assignment from GitLab using the command</p>

<p>A debugging note: <a href="http://andresabino.com/2015/04/14/codesign-gdb-on-mac-os-x-yosemite-10-10-2/">Check out this page on how to set up <em>gdb</em> to work with recent OS X releases</a>. Please use <em>gdb</em> to debug, particularly if you get a seg fault that you can't track! Turn on debug symbols by toggling this line at the top of the <em>CMakeLists.txt</em> file in the root directory:</p>

<pre><code>option(BUILD_DEBUG     "Build with debug settings"    ON)
</code></pre>

<p>You'll have to rerun <em>cmake</em> to update the Makefiles after doing this.</p>

<h2>Project structure</h2>

<p>The project has 8 parts, divided into 4 sections, worth a total of 100 possible points. Some require only a few lines of code, while others are more substantial.</p>

<p><strong>Section I: Bezier Curves and Surfaces</strong></p>

<ul>
<li>Part 1: Bezier curves with 1D de Casteljau subdivision (10 pts)</li>
<li>Part 2: Bezier surfaces with separable 1D de Casteljau subdivision (15 pts)</li>
</ul>

<p><strong>Section II: Loop Subdivision of General Triangle Meshes</strong></p>

<ul>
<li>Part 3: Average normals for half-edge meshes (10 pts)</li>
<li>Part 4: Half-edge flip (15 pts)</li>
<li>Part 5: Half-edge split (15 pts)</li>
<li>Part 6: Loop subdivision for mesh upsampling (25 pts)</li>
</ul>

<p><strong>Section III: Shaders</strong></p>

<ul>
<li>Part 7: Fun with shaders (10 pts)</li>
</ul>

<ul>
<li>Part 8: Design your own mesh!</li>
</ul>

<h2>Using the GUI</h2>

<p>When you have successfully built your code, you will get an executable named <code>meshedit</code> in the build directory. The <code>meshedit</code> executable takes exactly one argument from the command line. You may load a single COLLADA file by specifying its path. For example, to load the example file <em>dae/quadball.dae</em> from your build directory:</p>

<p><code>./meshedit ../dae/quadball.dae</code></p>

<p>In Section I Part I, you will be able to load Bezier curves by running a command such as:</p>

<p><code>./meshedit ../bzc/curve1.bzc</code></p>

<p>In Section I Part II, you will be able to load Bezier surfaces by running a command such as:</p>

<p><code>./meshedit ../bez/teapot.bez</code></p>

<p>When you first run the application, you will see a picture of a mesh made of triangles. The starter code that you must modify is drawing this mesh.  The editor already supports some basic functionality, like moving vertices around in space, which you can do by just clicking and dragging on a vertex.  You can also rotate the camera by right-clicking and dragging (or dragging on the background), and zoom in and out using the scroll wheel or multi-touch scrolling on a trackpad. Hitting the spacebar will reset the view.  As you move the cursor around the screen, you'll notice that mesh elements (faces, edges, and vertices) under the cursor get highlighted. Clicking on one of these elements will display some information about the element and its associated data.</p>

<p><img src="/uploads/article_images/9_3.jpg" alt="" /></p>

<p>In this assignment, you will add additional functionality to the program that allows you to modify the mesh in a variety of ways. Each of these methods is exposed through the viewer. There are two basic types of operations. Each operation will be executed with a key press.</p>

<ol>
<li>Local flip (<strong>F</strong>) and split (<strong>S</strong>) operations, which modify the mesh in a small neighborhood around the currently selected mesh element.</li>
<li>Loop subdivision (<strong>U</strong>), which refines and smooths the entire mesh.</li>
</ol>

<p>Here is the full specification on keyboard controls for the GUI:</p>

<p><center></p>

<table>
<thead>
<tr>
  <th>Command</th>
  <th align="center">Key</th>
</tr>
</thead>
<tbody>
<tr>
  <td>Flip the selected edge</td>
  <td align="center"><kbd>F</kbd></td>
</tr>
<tr>
  <td>Split the selected edge</td>
  <td align="center"><kbd>S</kdb></td>
</tr>
<tr>
  <td>Upsample the current mesh</td>
  <td align="center"><kbd>U</kdb></td>
</tr>
<tr>
  <td>Toggle information overlay</td>
  <td align="center"><kbd>I</kdb></td>
</tr>
<tr>
  <td>Toggle center points</td>
  <td align="center"><kbd>P</kdb></td>
</tr>
<tr>
  <td>Select the next halfedge</td>
  <td align="center"><kbd>N</kbd></td>
</tr>
<tr>
  <td>Select the twin halfedge</td>
  <td align="center"><kbd>T</kbd></td>
</tr>
<tr>
  <td>Switch to GLSL shaders</td>
  <td align="center"><kbd>W</kbd></td>
</tr>
<tr>
  <td>Switch between GLSL shaders</td>
  <td align="center"><kbd>0-9</kbd></td>
</tr>
<tr>
  <td>Toggle using area-averaged normals</td>
  <td align="center"><kbd>Q</kbd></td>
</tr>
<tr>
  <td>Recompile shaders</td>
  <td align="center"><kbd>R</kbd></td>
</tr>
<tr>
  <td>Reset camera to default position</td>
  <td align="center"><kbd>SPACE</kdb></td>
</tr>
<tr>
  <td>Edit a vertex position</td>
  <td align="center">(click and drag on vertex)</td>
</tr>
<tr>
  <td>Rotate camera</td>
  <td align="center">(click and drag on background, or right click)</td>
</tr>
</tbody>
</table>

<p></center></p>

<p>Note that each COLLADA file may contain multiple mesh objects; more generally, a COLLADA file describes a <strong>scene graph</strong> (much like SVG) that is a hierarchical representation of all objects in the scene (meshes, cameras, lights, etc.), as well as their coordinate transformations. Global resampling methods will be run on whichever mesh is currently selected.</p>

<h2>Getting Acquainted with the Starter Code</h2>

<p>Before you start, here is some basic information on the structure of the starter code. <strong>Your code for all parts except shading will be contained inside <em>student_code.cpp</em></strong>.</p>

<p>For Bezier curves and surfaces (Section I), you'll be filling in member functions of the  <code>BezierCurve</code> and <code>BezierPatch</code> classes, declared in <em>bezierCurve.&#42;</em> and <em>bezierPatch.&#42;</em>. We have put dummy definitions for all the <code>BezierCurve</code> and <code>BezierPatch</code> functions you need to implement inside <em>student_code.cpp</em>, where you'll be writing your code.</p>

<p>For half-edge meshes (Section II), you'll be filling in member functions of the <code>HalfedgeMesh</code> class, declared in <em>halfEdgeMesh.&#42;</em>. We have put dummy definitions for all the half-edge functions you need to modify inside <em>student_code.cpp</em>, where you'll be writing your code.</p>

<p>For shaders (Section III), you'll be editing the <em>shader/frag</em> file.</p>

<p>Before you attempt Section II, you'll want to consult lectures 10 and 11 as a half-edge refresher and then also read <a href="https://cs184.org/article/10">this in-depth article</a> with more detail about the half-edge data structure and its implementation in the starter code.</p>

<h2>Section I: Bezier Curves and Surfaces</h2>

<p>In Section I, we take a closer look at Bezier curves and surfaces. In computer graphics, Bezier curves and surfaces are parametric curves and surfaces that are frequently used to model smooth and indefinitely scalable curves and surfaces.</p>

<p>A Bezier curve of degree n is defined by (n + 1) control points. Similarly, a Bezier surface of degree (n, m) is defined by (n + 1)(m + 1) control points.</p>

<p>A Bezier curve is a parametric curve defined by a single parameter, t, which ranges between 0 and 1. Similarly, a Bezier surface is a parametric surface defined by two parameters, u and v. Using de Casteljau's algorithm, we can evaluate these parametric curves and surfaces for any given set of parameters.</p>

<p><img src="/uploads/article_images/9_20.jpg" alt="" /></p>

<h3>Part 1: Bezier curves with 1D de Casteljau subdivision (10 pts)</h3>

<p><a href="https://cs184.org/lecture/curves-surfaces"><strong>Relevant lectures: 9</strong></a></p>

<p>In Part 1, we will work with generic Bezier curves, though we will look at cubic Bezier curves as our motivating example and extend the concept from there to support any order Bezier curve.</p>

<p>To get started, take a look at <em>bezierCurve.h</em> and examine the protected variables defined within the class. Let's briefly go over the purpose of ones you will primarily be concerned with:</p>

<ul>
<li><code>std::vector&lt;Vector2D&gt; controlPoints</code>: A vector containing exactly control points that define the Bezier curve. This vector is initialized with the control points of the Bezier curve file passed in.</li>
<li><code>std::vector&lt; std::vector&lt;Vector2D&gt; &gt; evaluatedLevels</code>: A 2D vector containing the evaluated points at each level of subdivision when applying de Casteljau's algorithm. Initially, it contains a single vector representing the starting level containing just the original control points. You should add additional levels with their respective "intermediate control points" every time <code>evaluateStep</code> is called. For example, a cubic Bezier curve should have 4 total levels, where the first level contains the original control points and the final level contains just a single evaluated point that represents $B(t)$ (the Bezier curve evaluated at t).</li>
<li><code>float t</code>: A parameter varying between 0.0 and 1.0 at which to evaluate the Bezier curve.</li>
</ul>

<p>Implement <code>evaluateStep</code>, which looks at the control points from the most recently evaluated leveland performs de Casteljau's algorithm to compute the next level of intermediate control points. These intermediate control points at each level should be appropriately stored into the member variable <code>evaluatedLevels</code>, which is used by the program to render the Bezier curve.</p>

<h4>Implementation Notes</h4>

<ul>
<li><code>evaluatedLevels</code> is seeded with the original control points of the Bezier curve, so you should already have a "most recent level" to look at and use to compute your first set of intermediate control points.</li>
<li><strong>DO NOT</strong> use or modify the variable <code>eval_level</code> defined in <code>bezierCurve.h</code>. This is used internally for rendering the curve.</li>
<li><code>std::vector</code> is similar to Java's <code>ArrayList</code> class; you should use <code>std::vector</code>'s <code>push_back</code> method to add elements, which is analogous to Java's <code>ArrayList</code>'s <code>append</code> method.</li>
</ul>

<p>Recall from lecture that de Casteljau's algorithm gives us the following recursive step that we can repeatedly apply to evaluate a Bezier curve:</p>


<p><code>evaluateStep</code> should return immediately if the Bezier curve has already been completely evaluated at t (i.e. <code>evaluateStep</code> has already been called enough times to completely solve for the point at B(t)).</p>

<p>Check your implementation by running the program with this syntax: <code>./meshedit &lt;path to .bzc file&gt;</code>:</p>

<pre><code>./meshedit ../bzc/curve1.bzc
</code></pre>

<p><em>bzc/curve1.bzc</em> is a cubic Bezier curve, whereas <em>bzc/curve2.bzc</em> is a degree-4 Bezier curve. Feel free to play around with higher-order Bezier curves by creating your own <em>bzc</em> files.</p>

<h4>Using the GUI: Part 1</h4>

<p>For this Part only, the GUI is a little different. There are two keyboard commands:</p>

<ul>
<li><strong>E</strong>: Perform one call to <code>evaluateStep</code>; will cycle through the levels once fully evaluated</li>
<li><strong>C</strong>: Toggles whether or not the entirely evaluated Bezier curve is drawn to the screen</li>
</ul>

<p>Step through the evaluation of $B(t)$ by repeatedly pressing <strong>E</strong> to verify your implementation is correct. Toggle the Bezier curve using <strong>C</strong> to check that the  curve correctly follows from its control points.</p>

<p>Besides these keyboard commands, there are some neat controls with your mouse:</p>

<ul>
<li><strong>Click and drag</strong> the control points to move them and see how your Bezier curve (and all intermediate control points) changes accordingly</li>
<li><strong>Scroll</strong> to move the evaluated point along the Bezier curve and see how the intermediate control points move along with it; this is essentially varying $t$ between 0.0 and 1.0</li>
</ul>

<h3>Part 2: Bezier surfaces with separable 1D de Casteljau subdivision (15 pts)</h3>

<p><a href="https://cs184.org/lecture/curves-surfaces"><strong>Relevant lectures: 9</strong></a></p>

<p>In Part 2, we will work only with cubic Bezier surfaces.</p>

<p>To get started, take a look at <em>bezierPatch.h</em> and examine the class definition. In this part, you will be working with:</p>

<ul>
<li><code>std::vector&lt; std::vector&lt;Vector3D&gt; &gt; controlPoints</code>: A 2D vector representing a 4x4 grid of control points that define the cubic Bezier surface. This variable is initialized with all 16 control points.</li>
<li><code>Vector3D evaluate(double u, double v) const</code>: You will fill this function in, which evaluates the Bezier curve at parameters (u, v). In mathematical terms, it computes B(u, v).</li>
<li><code>Vector3D evaluate1D(std::vector&lt;Vector3D&gt; points, double t) const</code>: An optional helper function that you might find useful to implement to help you with your implementation of <code>evaluate</code>. Given an array of 4 points that lie on a single curve, evaluates the curve at parameter t using 1D de Casteljau subdivision.</li>
</ul>


<p>Implement <code>evaluate</code>, which completely evaluates the Bezier surface at parameters u and v. Unlike Part 1, you will not perform just a single step at a time -- you will instead completely evaluate the Bezier surface using the specified parameters. This function should return that final evaluated point.</p>

<p>Use the following algorithm to repeatedly apply separable 1D de Casteljau's algorithm in both dimensions to evaluate the Bezier surface:</p>

<pre><code>For each row i:
  Let q(i, u) := apply de Casteljau's algorithm with parameter u to the i-th row of control points

Let p(u, v) := apply de Casteljau's algorithm with parameter v to all q(i, u) 
Return p(u, v)
</code></pre>

<p>If your implementation is correct, you should see a teapot by running the following command:</p>

<pre><code>./meshedit ../bez/teapot.bez
</code></pre>

<h2>Section II: Loop Subdivision of General Triangle Meshes</h2>

<p>In Section I, we dealt with Bezier curves and surfaces, parametric functions that were defined by a set of control points. Through de Casteljau's algorithm, we performed subdivision that allowed us to evaluate those functions.</p>

<p>With Bezier curves, we performed 1D subdivision, and evaluation steps were relatively simple since adjacent control points were trivially retrieved from a 1D vector. With Bezier surfaces, we applied the same 1D subdivision concepts in both dimensions, and evaluation steps were a little more complicated, but adjacent control points were still easily retrieved from the 2D grid of control points.</p>

<p>What about generic triangle meshes? Here, the only rules are that our mesh is made up of triangles and that the triangles connect to each other through their edges and vertices. There is no constraining 2D grid as before with Bezier surfaces. As a result, adjacency is unfortunately no longer trivial. Enter the half-edge data structure, a powerful and popular data structure commonly used to store mesh entities and their connectivity information.</p>

<p><strong>Note:</strong> Before diving into Section II, be sure to first read <a href="https://cs184.org/article/10">this article</a> to help you navigate the <code>HalfedgeMesh</code> class, which you will use extensively in the next section of the project.</p>

<h3>Part 3: Average normals for half-edge meshes (10 pts)</h3>

<p><a href="https://cs184.org/lecture/pipeline"><strong>Relevant lecture: 7</strong></a></p>

<p>For Part 3, make sure you understand the code given for a <code>printNeighborPositions</code> function as well.</p>

<p>In this part, you will implement the <code>Vertex::normal</code> function inside <em>student_code.cpp</em>. This function returns the area-weighted average normal vector at a vertex, which can then be used for more realistic local shading compared to the default flat shading technique. <a href="https://cs184.org/lecture/pipeline/slide_064">This slide</a> depicts this graphically.</p>

<p>In order to compute this value, you will want to use a <code>HalfedgeIter</code> to point to the <code>Halfedge</code> you are currently keeping track of. A <code>HalfedgeIter</code> (analogously <code>VertexIter</code>, <code>EdgeIter</code>, and <code>FaceIter</code>) is essentially a pointer to a <code>Halfedge</code> (respectively <code>Vertex</code>, <code>Edge</code>, and <code>Face</code>), in the sense that you will use <code>-&gt;</code> to dereference its member functions. Also, you can test whether two different iterators point to the same object using <code>==</code>, and you can assign one iterator to point to the same thing as another using <code>=</code> (this will NOT make the pointed-to objects have the same value, just as with pointers!).</p>

<p><strong>Technical implementation caveat</strong>: For this part only, you're implementing a <code>const</code> member function, which means you need to use <code>HalfedgeCIter</code>s instead of <code>HalfedgeIter</code>s. These merely promise not to change the values of the things they point to.</p>

<p>The relevant member functions for this task are <code>Vertex::halfedge()</code>, <code>Halfedge::next()</code> and <code>Halfedge::twin()</code>. You will also need the public member variable <code>Vector3D Vertex::position</code>.</p>

<p>How you might use these to begin implementing this function:</p>

<pre><code>Vector3D n(0,0,0); // initialize a vector to store your normal sum
HalfedgeCIter h = halfedge(); // Since we're in a Vertex, this returns a halfedge
                             // pointing _away_ from that vertex
h = h-&gt;twin(); // Bump over to the halfedge pointing _toward_ the vertex.
               // Now h-&gt;next() will be another edge on the same face,
               // sharing the central vertex.
</code></pre>

<p>At this point, you should</p>

<ol>
<li>Save a copy of <code>h</code>'s value in another <code>HalfedgeCIter h_orig</code>.</li>
<li>Start a <code>while</code> loop that ends when <code>h == h_orig</code>.</li>
<li>Inside each loop iteration: 

<ul>
<li>Accumulate area-weighted normal of the current face in the variable <code>n</code>. You can do this by using the cross product of triangle edges. We've defined the cross product for you, so don't re-implement it yourself! Since the cross product of two vectors has a norm equal to twice the area of the triangle they define, these vectors are <em>already area weighted</em>!</li>
<li>Once you've added in the area-weighted normal, you should advance <code>h</code> to the halfedge for the next face by using the <code>next()</code> and <code>twin()</code> functions.</li>
</ul></li>
<li>After the loop concludes, return the re-normalized unit vector <code>n.unit()</code>.</li>
</ol>

<p>After completing this part, load up a <em>dae</em> such as <em>dae/teapot.dae</em> and press <strong>W</strong> to switch to GLSL shaders and then press <strong>Q</strong> to toggle area-averaged normal vectors (which will call on your <code>Vertex::normal</code> function). Here's an example of what <em>dae/teapot.dae</em> should look like with correctly implemented area-averaged normals.</p>

<p><img src="/uploads/article_images/9_18.jpg" alt="" /></p>

<p>It should NOT look like this!</p>

<p><img src="/uploads/article_images/9_19.jpg" alt="" /></p>

<h3>Part 4: Half-edge flip (15 pts)</h3>

<p><strong>Relevant lectures: <a href="https://cs184.org/lecture/mesh-representations">10</a>, <a href="https://cs184.org/lecture/geometry-processing">11</a></strong></p>

<p>Now you should be a little more comfortable traversing the half-edge pointers. In this task, you will implement a more substantial method: a local remeshing operation that "flips" an edge, implemented inside the method <code>HalfedgeMesh::flipEdge</code> in file <em>student_code.cpp</em>.</p>

<p>More precisely, suppose we have a pair of triangles (a,b,c) and (c,b,d). After flipping the edge (b,c), we should now have triangles (a,d,c) and (a,b,d):</p>

<p><img src="/uploads/article_images/9_9.jpg" alt="" /></p>

<p>Your solution should:</p>

<ul>
<li>Never flip boundary edges (just return immediately if either neighboring face is a boundary loop). Every object has a useful <code>boundary()</code> function that can tell you if it is or is not on the boundary.</li>
<li>Perform only a constant amount of work -- the cost of flipping a single edge should <strong>not</strong> be proportional to the size of the mesh!</li>
<li>Not add or delete any elements.  Since there are the same number of mesh elements before and after the flip, you should only need to reassign pointers.</li>
</ul>

<p>The biggest challenge in properly implementing this operation (as well as split) is making sure that all the pointers still point to the right place in the modified mesh. An easy recipe for ensuring that all pointers are still valid after any general remeshing operation is:</p>

<ol>
<li>Draw a picture and/or write down a list of all the elements (vertices, edges, faces, halfedges) that will be needed from the original mesh.</li>
<li>Draw a picture and/or write down a list of all the elements that should appear in the modified mesh.</li>
<li>Allocate any new elements that are needed in the modified mesh, but do not appear in the original mesh (only relevant for the next part).</li>
<li>For every element in the "modified" picture, set <strong>all</strong> of its pointers -- even if they didn't change. For instance, for each halfedge, make sure to set <code>next</code>, <code>twin</code>, <code>vertex</code>, <code>edge</code>, and <code>face</code> to the correct values in the new (modified) picture. For each vertex, edge, and face, make sure to set its <code>halfedge</code> pointer. A convenience method <code>Halfedge::setNeighbors()</code> has been created for the purpose of setting all pointers inside a halfedge at once.</li>
</ol>

<p>The reason for setting all the pointers (and not just the ones that changed) is that it is very easy to miss a pointer, causing your code to fail. Once the code is <strong>working</strong>, you can remove these unnecessary assignments if you wish.</p>

<p><em>Tip:</em> You can check which other objects in the mesh point to a given object by using the debug functions <code>check_for</code> inside <code>HalfEdgeMesh</code>. There's more information about these functions at the bottom of the halfedge documentation article.</p>

<h3>Part 5: Half-edge split (15 pts)</h3>

<p><strong>Relevant lectures: <a href="https://cs184.org/lecture/mesh-representations">10</a>, <a href="https://cs184.org/lecture/geometry-processing">11</a></strong></p>

<p>This time, you will make a different local modification to the mesh in the neighborhood of an edge, called a <strong>split</strong>. In particular, suppose we have a pair of triangles (a,b,c) and (c,b,d). The edge (b,c) is split by inserting a new vertex m at its midpoint and connecting it to the opposite vertices a and d, yielding four triangles:</p>

<p><img src="/uploads/article_images/9_10.jpg" alt="" /></p>

<p>This task is a bit tricker than "flip" because there are more pointers to keep track of, and you will have to allocate new mesh elements this time (e.g., two new triangles, three edges, some halfedges...).  Your implementation should:</p>

<ul>

<li>Assign the position of the new vertex to the midpoint of the original edge, i.e., the average of its two endpoints (see <code>Vertex::position</code>).</li>
<li>Perform only a constant amount of work -- the cost of splitting a single edge should <strong>not</strong> be proportional to the size of the mesh!</li>
<li>Allocate only as many new elements as needed; there should be no "orphaned" elements that are not connected to the rest of the mesh.</li>
</ul>

<p>To obtain a correct implementation, you might try following the same "recipe" given in the previous task (though clever, clean, and simple alternatives are of course always welcome). To verify that your implementation works correctly, try flipping some edges that you've split, and splitting some edges that you flipped. Further, alternate between flipping and splitting edges at least ten times in nearby and far-apart regions of the mesh and check that your mesh changes appropriately.</p>

<p><em>Tip:</em> You can check which other objects in the mesh point to a given object by using the debug functions <code>check_for</code> inside <code>HalfEdgeMesh</code>. There's more information about these functions at the bottom of the halfedge documentation article.</p>


<h3>Part 6: Loop subdivision for mesh upsampling (25 pts)</h3>

<p><a href="https://cs184.org/lecture/geometry-processing"><strong>Relevant lectures: 11</strong></a></p>

<p>Now, we can leverage the previous two parts to make implementing the mesh topology changes in Loop subdivision very simple! In this task, you will implement the whole Loop subdivision process inside the <code>MeshResampler::upsample</code> in <em>student_code.cpp</em>.</p>

<p>Loop subdivision is somewhat analogous to upsampling using some interpolation method in image processing: we may have a low-resolution polygon mesh that we wish to upsample for display, simulation, etc.  Simply splitting each polygon into smaller pieces doesn't help, because it does nothing to alleviate blocky silhouettes or chunky features. Instead, we need an upsampling scheme that nicely interpolates or approximates the original data. Polygon meshes are quite a bit trickier than images, however, since our sample points are generally at <em>irregular</em> locations, i.e., they are no longer found at regular intervals on a grid.</p>

<p>Loop subdivision consists of two basic steps:</p>

<ol>
<li>Change the mesh topology: split each triangle into four by connecting edge midpoints (sometimes called "4-1 subdivision").</li>
<li>Update vertex positions as a weighted average of neighboring positions.</li>
</ol>

<p>4-1 subdivision does this to each triangle:</p>

<p><center>
<img src="/uploads/article_images/9_11.jpg" width="500px" align="middle"/>
</center></p>

<p>And the following picture depicts the correct weighting for the new averaged vertex positions:</p>

<p><center>
<img src="/uploads/article_images/9_13.jpg" width="500px" align="middle"/>
</center></p>

<p>Written out, the new position of an old vertex is</p>

<pre><code>(1 - n*u) * original_position + u * neighbor_position_sum
</code></pre>

<p>where <code>n</code> is the number of neighboring vertices, <code>u</code> is a constant as depicted in the figure above, <code>original_position</code> is the vertex's original position, and <code>neighbor_position_sum</code> is the sum of all neighboring vertices' positions.</p>

<p>The position for a newly created vertex v that splits an edge AB connecting vertices A and B and is flanked by opposite vertices C and D across the two faces connected to AB in the original mesh will be</p>

<pre><code>3/8 * (A + B) + 1/8 * (C + D)
</code></pre>

<p>If we repeatedly apply these two steps, we will converge to a smoothed approximation of our original mesh.  In this task you will implement Loop subdivision, leveraging the split and flip operations to handle the topology changes.  In particular, you can achieve a 4-1 subdivision by applying the following strategy:</p>

<ol>
<li>Split every edge of the mesh in any order whatsoever.</li>
<li>Flip any new edge that touches a new vertex and an old vertex. <em>Note</em>: Every original edge will now be represented by 2 edges, you <em>should not</em> flip these edges, because they are always already along the boundary of the 4 way divided triangles. In the diagrams below, you should only flip the blue edges that connect an old and new vertex, but you should not flip any of the black new edges.</li>
</ol>

<p>The following pictures (courtesy Denis Zorin) illustrate this idea:</p>

<p><img src="/uploads/article_images/9_14.jpg" alt="" /></p>

<h4>Implementation walkthrough</h4>

<p>For Loop subdivision, we have also provided some additional data members that will make it easy to keep track of the data you need to update the connectivity and vertex positions. In particular:</p>

<ul>
<li><code>Vertex::newPosition</code> can be used as temporary storage for the new position (computed via the weighted average above).  Note that you should <em>not</em> change the value of <code>Vertex::position</code> until <em>all</em> the new vertex positions have been computed -- otherwise, you are taking averages of values that have already been averaged!</li>
<li>Likewise, <code>Edge::newPosition</code> can be used to store the position of the vertices that will ultimately be inserted at edge midpoints.  Again, these values should be computed from the original values (before subdivision), and applied to the new vertices only at the very end. The <code>Edge::newPosition</code>value will be used for the position of the vertex that will appear along the old edge after the edge is split. We precompute the position of the new vertex before splitting the edges and allocating the new vertices because it is easier to traverse the simpler original mesh to find the positions for the weighted average that determines the positions of the new vertices.</li>
<li><code>Vertex::isNew</code> can be used to flag whether a vertex was part of the original mesh, or is a vertex newly inserted by subdivision (at an edge midpoint).</li>
<li><code>Edge::isNew</code> likewise flags whether an edge is a piece of an edge in the original mesh, or is an entirely new edge created during the subdivision step.</li>
</ul>

<p>Given this setup, we strongly suggest that it will be easiest to implement subdivision according to the following "recipe" (though you are of course welcome to try doing things a different way!). The basic strategy is to <em>first</em> compute the new vertex positions (storing the results in the <code>newPosition</code> members of both vertices and edges), and only <em>then</em> update the connectivity. Doing it this way will be much easier, since traversal of the original (coarse) connectivity is much simpler than traversing the new (fine) connectivity. In more detail:</p>

<ol>
<li>Mark all vertices as belonging to the original mesh by setting <code>Vertex::isNew</code> to <code>false</code> for all vertices in the mesh.</li>
<li>Compute updated positions for all vertices in the original mesh using the vertex subdivision rule, and store them in <code>Vertex::newPosition</code>.</li>
<li>Compute new positions associated with the vertices that will be inserted at edge midpoints, and store them in <code>Edge::newPosition</code>.</li>
<li>Split every edge in the mesh, being careful about how the loop is written.  In particular, you should make sure to iterate only over edges of the original mesh.  Otherwise, you will keep splitting edges that you just created!</li>
<li>Flip any new edge that connects an old and new vertex.</li>
<li>Finally, copy the new vertex positions (<code>Vertex::newPosition</code>) into the usual vertex positions (<code>Vertex::position</code>).</li>
</ol>

<p>If you made the requested modification to the return value of <code>HalfedgeMesh::splitEdge()</code> (see above), then an edge split will now return an iterator to the newly inserted vertex, and the halfedge of this vertex will point along the edge of the original mesh. This iterator is useful because it can be used to (i) flag the vertex returned by the split operation as a new vertex, and (ii) flag each outgoing edge as either being new or part of the original mesh.  (In other words, Step 3 is a great time to set the members <code>isNew</code> for vertices and edges created by the split. It is also a good time to copy the <code>newPosition</code> field from the edge being split into the <code>newPosition</code> field of the newly inserted vertex.)</p>

<p>You might try implementing this algorithm in stages, e.g., <em>first</em> see if you can correctly update the connectivity, <em>then</em> worry about getting the vertex positions right. Some examples below illustrate the correct behavior of the algorithm.</p>

<p><img src="/uploads/article_images/9_12.jpg" alt="" /></p>





<h2>Section III: Shaders</h2>

<h3>Part 7: Fun with shaders (10 pts)</h3>

<p><a href="https://cs184.org/lecture/pipeline"><strong>Relevant lecture: 7</strong></a></p>

<p>For this part, you will implement Phong shading. Take a look at <a href="https://cs184.org/lecture/pipeline/slide_051">these slides</a> to review the basic concepts and variables used in shading equations.</p>


<p>Here is a list of functions you will need to modify inside <em>shader/frag</em>:</p>

<ol>
<li><code>shadePhong</code></li>
</ol>

GLSL Tutorials: <a href="http://joshbeam.com/articles/getting_started_with_glsl/">Here</a> is a short tutorial on GLSL. It should have everything you need to know about this part of the assignment. 



<h4>Reference Images</h4>

<h5>Phong Shading (required for Part 7)</h5>

<p><img src="/uploads/article_images/9_4.jpg" alt="" /></p>



<p><img src="/uploads/article_images/9_6.jpg" alt="" /></p>



<p><img src="/uploads/article_images/9_7.jpg" alt="" /></p>



<p><img src="/uploads/article_images/9_8.jpg" alt="" /></p>

<p><img src="/uploads/article_images/9_5.jpg" alt="" /></p>


<h2>Submission</h2>

To be done on LMS
