# Assignment 5: Cloth Simulation

<html>
<head>
</head>
<body>

<div class="markdown article-content">
<h2>Overview</h2>

<p>In this Assignment, you will implement a real-time simulation of cloth using a mass and spring based system. You will build the data structures to discretely represent the cloth, define and apply physical constraints on them, and apply numerical integration to simulate the way cloth moves over time. Finally, you will implement collisions with other objects as well as self-collisions to prevent cloth clipping.</p>

<h2>Deadline</h2>

<p>This Assignment is due on Tuesday, 4th December at 11:55pm.</p>

<h2>Structure</h2>

<p>The Assignment has 4 parts worth a total of 100 possible points. Some require only a few lines of code, while others are more substantial.</p>

<ul>
<li>Part 1: Masses and springs</li>
<li>Part 2: Simulation via numerical integration</li>
<li>Part 3: Handling collisions with other objects</li>
<li>Part 4: Handling self-collisions</li>
<li>Part 5: Extra credit: Additional cloth simulation features!</li>
</ul>


<h2>Getting started</h2>

<p>You can clone the assignment from GitLab using the command</p>

<pre><code>git clone https://github.com/mkarsalan/PA5-Simulation
</code></pre>

<h2>Building and running the program</h2>

<p>Before moving forward, you need to have nanoGUI installed. In your assignment directory, execute this command:</p>

<p><code>mkdir ext; cd ext; git clone https://github.com/wjakob/nanogui --recursive; cd nanogui; mkdir build; cd build; cmake ..; make -j8</code></p>

<p>Then go back to your assignment directory and exectue:</p>

<p><code>mkdir build; cd build; cmake ..; make</code></p>

<p>After you have built the program using <code>make</code>, you will have an executable file <code>clothsim</code> that takes in zero or one argument. Running the program with zero arguments will load up the default scene (<code>scene/pinned2.json</code>). Otherwise, to load a specific scene, run the program as follows:</p>

<pre><code>./clothsim -f ../scene/&lt;my_scene&gt;.json
</code></pre>

<p>For example, running the following command without any code will produce an empty scene.</p>

<pre><code>./clothsim
</code></pre>

<h2>Getting acquainted with the starter code</h2>

<p>Before you start, here is some basic information on the structure of the starter code.</p>

<ul>
<li><em>cloth.cpp/h</em>: The cloth representation, as well as methods that directly change the cloth during the simulation</li>
<li><em>clothSimulator.cpp/h</em>: The primary program that wraps around the cloth and its constituents and runs the simulation and GUI</li>
<li><em>spring.h</em>: A struct definition for a simple spring in our mass-spring system that represents a connection between two point masses</li>
<li><em>pointMass.h</em>: A struct definition for a single point mass that discretizes the cloth and is affected by forces (e.g. spring forces, gravity) in the system</li>
<li><em>collision/</em>: Directory containing struct definitions for static primitive objects, such as <em>sphere.cpp/h</em> and <em>plane.cpp/h</em></li>
<li><em>scene/</em>: Directory containing various scenes saved in JSON format</li>
</ul>

<p>In this Assignment, you will write code in <em>cloth.cpp</em>, <em>collision/sphere.cpp</em>, and <em>collision/plane.cpp</em>.</p>

<h2>Using the GUI</h2>

<p><center>
<img src="https://cs184.eecs.berkeley.edu/cs184_sp17_content/article_images/25_7.jpg" width="800px" />
</center></p>

<p>Besides the actual graphical user interface that you can work with using your mouse to tweak cloth parameters and dynamically change external forces, there are several keyboard commands that you might find useful.</p>

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
  <td>Pause simulation</td>
  <td align="center"><kbd>P</kbd></td>
</tr>
<tr>
  <td>(while paused) Go forward 1 timestep</td>
  <td align="center"><kbd>N</kbd></td>
</tr>
<tr>
  <td>Restart simulation</td>
  <td align="center"><kbd>R</kbd></td>
</tr>
<tr>
  <td>End simulation</td>
  <td align="center"><kbd>ESCAPE</kbd></td>
</tr>
<tr>
  <td>Reset camera to default position</td>
  <td align="center"><kbd>SPACE</kdb></td>
</tr>
<tr>
  <td>Rotate camera</td>
  <td align="center">(click and drag, or right click)</td>
</tr>
<tr>
  <td>Pan camera</td>
  <td align="center">(hold control + click and drag, or right click)</td>
</tr>
</tbody>
</table>

<p></center></p>

<h2>Part 1: Masses and springs</h2>

<p>Throughout the history of computer graphics, many different cloth models have been developed for simulation. Of these, one of the simplest models uses a system of point masses and springs. Given a sheet of cloth with some desired dimensions and parameters, we can divide the cloth up into evenly spaced point masses and then connect nearby masses with springs.</p>

<p>Before writing any code, look over the struct definitions in <em>spring.h</em>, <em>pointMass.h</em>, and <em>cloth.h</em>.</p>

<p>Then, complete the function <code>Cloth::buildGrid</code> in <em>cloth.cpp</em>, which takes the cloth's parameters and populates the cloth's <code>point_masses</code> and <code>springs</code> vectors with the necessary point masses and springs, respectively, in the grid.</p>

<h3>Building a grid of masses and springs</h3>

<p>Start by creating an evenly spaced grid of masses. There should be <code>num_width_points</code> by <code>num_height_points</code> total masses spanning <code>width</code> and <code>height</code> lengths, respectively. If the cloth's <code>orientation</code> is <code>HORIZONTAL</code>, then set the <code>y</code> coordinate for all point masses to 1 while varying positions over the <code>xz</code> plane. Otherwise (i.e. the <code>orientation</code> is <code>VERTICAL</code>), generate a small random offset between -1/1000 and 1/1000 for each point mass and use that as the <code>z</code> coordinate while varying positions over the <code>xy</code> plane. You may find the <code>rand()</code> function useful. Let the top left (first) point mass be at coordinate (0, 0) and the bottom right (last) point mass be at coordinate (width, height) with respect to the varying plane.</p>

<p>If the point mass's <code>(x, y)</code> index is within the cloth's <code>pinned</code> vector, then set the point mass's <code>pinned</code> boolean to <code>true</code>.</p>

<p>Store these point masses in the <code>point_masses</code> vector <strong>IN ROW-MAJOR (X-AXIS) ORDER</strong> (or else the rendering will not work properly).</p>

<p>Next, create springs to apply the structual, shear, and bending constraints between point masses. Each of these springs takes in pointers to the two point masses that belong at the two ends of the spring and an enum that represents the type of constraint (<code>STRUCTURAL</code>, <code>SHEARING</code>, or <code>BENDING</code>).</p>

<ol>
<li>Structural constraints exist between a point mass and the point mass to its left as well as the point mass above it.</li>
<li>Shearing constraints exist between a point mass and the point mass to its diagonal upper left as well as the point mass to its diagonal upper right.</li>
<li>Bending constraints exist between a point mass and the point mass two away to its right as well as the point mass two above it.</li>
</ol>

<h3>Implementation tips</h3>

<ul>
<li>Make sure to account for edge (literally) cases.</li>
<li>Pointer arithmetic can make things a lot easier here.</li>
<li>Since <code>point_masses</code> is a 1-dimensional vector, review how to convert a point mass's 2-D grid index into a 1-D vector index.</li>
</ul>

<h3>Test your implementation</h3>

<pre><code>./clothsim -f ../scene/pinned4.json
</code></pre>

<p>You should see a horizontally flat cloth wireframe similar to the image below (after moving the camera around a bit).</p>

<p>To make sure your springs are correctly created, try enabling and disabling the three different constraints on the GUI. You should see some springs appear and disappear accordingly; make sure they are the ones you expected to appear and disappear!</p>

<p><center>
<img src="https://cs184.eecs.berkeley.edu/cs184_sp17_content/article_images/25_.jpg" width="800px" />
</center></p>

<p>Pop quiz: What's happening in the above image?</p>

<h2>Part 2: Simulation via numerical integration</h2>

<p>Now that we have set up the cloth model as a system of masses and springs, we need to integrate the physical equations of motion in order to apply the forces on our cloth's point masses to figure out how they move from one time step to the next.</p>

<p>Take a look at <code>Cloth::simulate</code> in <em>cloth.cpp</em>. This method runs one time step in the simulation of time length <code>delta_t</code> (dt in equations below) and applies the <code>accelerations</code> uniformly to all point masses in the cloth. The <code>ClothParameters *cp</code> argument contains the parameters that characterize the cloth and its simulation, such as the spring constant <code>ks</code> and which spring constraints to simulate. <code>collision_objects</code> contains all of the objects in the scene that the cloth needs to check for collisions with at each time step.</p>

<p>In our representation, there are two kinds of forces: <strong>external forces</strong> (such as gravity) which uniformly affect the cloth and <strong>spring correction forces</strong> which apply the spring constraints from before to keep the cloth together. The external forces are captured by <code>external_accelerations</code>. On the other hand, the spring correction forces vary between point masses and will be computed based on the state of each spring.</p>

<p>Complete the rest of the <code>Cloth::simulate</code> method:</p>

<h3>2.1: Compute total force acting on each point mass</h3>

<p><strong>Note:</strong> <em>Every point mass has a vector representing the total force vector acting upon it called <code>forces</code>. Use this vector to accumulate the forces acting on each point mass as you compute them. Be sure to clear/reset them at the start of each call to simulate so as to not accumulate extra, nonexistant forces.</em></p>

<p>First, compute a total external force based on the <code>external_accelerations</code> and the <code>mass</code> (recall that Newton's 2nd Law states that F = ma). Apply this external force to every point mass.</p>

<p>Next, apply the spring correction forces. For each spring, skip over the spring if that spring's constraint type is currently disabled. You can check this using <code>cp</code>, which has boolean values such as <code>enable_structural_constraints</code>. Otherwise, compute the force applied to the two masses on its ends using Hooke's law:</p>

you can look at the equations here https://cs184.org/article/25

<p>F_s = k_s * (|| p_a - p_b || - l)</p>

<p>where k_s is the spring constant (<code>ks</code>), p_a and p_b are the positions of the two masses, || indicates magnitude, and l is the spring's rest length (<code>rest_length</code>). The force vector is the vector pointing from one point mass to the other with magnitude equal to ||F_s||. Apply this force to one point mass and an equal, but opposite force to the other.</p>

<h3>2.2: Use Verlet integration to compute new point mass positions</h3>

<p>Now that we have computed the force acting on each point mass for this time step, we need to perform numerical integration to compute each point mass's change in position. There are many ways of integrating our equations, which include Euler's method (explicit and implicit), Verlet algorithm, Runge-Kutta method, and more. Here, we will use Verlet integration, an explicit integrator that is fairly accurate and relatively easy to implement.</p>

<p>Verlet integration computes a point mass's new position at time t + dt, x_{t + dt} as follows:</p>

<p>x_{t + dt} = x_t + v_t * dt + a_t * dt^2</p>

<p>where x_t is the current position, v_t is the current velocity, a_t is the current total acceleration from all forces, and dt is a timestep <code>delta_t</code>.</p>

<p>In Verlet integration, we approximate v_t * dt = x_t - x_{t - dt}, where x_{t - dt} is the position from the last time step.</p>

<p>x_{t + dt} = x_t + (x_t - x_{t - dt}) + a_t * dt^2</p>

<p>This can be simplified to the following expression:</p>

<p>x_{t + dt} = 2x_t - x_{t - dt} + a_t * dt^2</p>

<p>However, we can add some damping into the simulation to help simulate loss of energy due to friction, heat loss, etc. by slightly scaling down v_t:</p>

<p>x_{t + dt} = x_t + (1 - d) * (x_t - x_{t - dt}) + a_t * dt^2</p>

<p>where d is a damping term (usually very small) between 0 and 1. Let d be the given <code>damping</code> value in <code>cp</code>. Note that the <code>damping</code> value is in units of percentage, so divide by 100 before subtracting from 1.</p>

<p>For each point mass, update the value in <code>position</code> according to the above equations and store the previous time step's position in <code>last_position</code>. <strong>Do not do anything if the point mass is pinned!</strong></p>

<h3>2.3: Constrain position updates</h3>

<p>To help keep springs from being unreasonably deformed during each time step, we will implement an additional feature based on the <a href="http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.84.1732&amp;rep=rep1&amp;type=pdf">SIGGRAPH 1995 Provot paper</a> on deformation constraints in mass-spring models (see Section 5 for specific details).</p>

<p>For each spring, apply this constraint by correcting the two point masses' positions such that the spring's length is at most 10% greater than its <code>rest_length</code> at the end of any time step. Maintain the same vector direction between the two point masses and only modify their distance apart from each other. Perform half of the correction to each point mass, unless one of them is pinned, in which case apply the correction entirely to one point mass. Do nothing if both are pinned (they wouldn't satisfy the condition anyways, by construction; can you see why?).</p>

<h3>Test your implementation</h3>

<pre><code>./clothsim -f ../scene/pinned2.json
</code></pre>

<p>You should see your cloth (with 2 corners pinned) fall down fairly realistically to a rest state!</p>

<p><center>
<img src="https://cs184.eecs.berkeley.edu/cs184_sp17_content/article_images/25_1.jpg" width="800px" />
</center></p>

<p><center>
<img src="https://cs184.eecs.berkeley.edu/cs184_sp17_content/article_images/25_9.jpg" width="800px" />
</center></p>

<h2>Part 3: Handling collisions with other objects</h2>

<p>Next, let's add support for cloth collision with other objects in the scene to make things more interesting.</p>

<p>Take a look at the <em>collision/</em> directory, which contains struct definitions for a sphere and a plane. For both <em>sphere.cpp</em> and <em>plane.cpp</em>, you will implement the <code>collide</code> method. At a high level, the <code>collide</code> method will determine whether or not a given point mass is inside the primitive. If it is, we adjust the point mass's position so that it stays just outside the primitive's surface, accounting for friction as we do so.</p>

<h3>3.1: Handling collisions with spheres</h3>

<p>Before writing any code, look at the struct definition for a sphere in <em>collision/sphere.h</em>.</p>

<p>Implement <code>Sphere::collide</code>, which takes in a point mass and adjusts its position if it intersects with or is inside the sphere. If the point mass intersects with or is inside the sphere, then "bump" it up to the surface of the sphere:</p>

<ol>
<li>Compute where the point mass should have intersected the sphere, if it had travelled in a straight line from its <code>position</code> towards the sphere's origin. Call this the tangent point.</li>
<li>Compute the correction vector needed to be applied to the point mass's <code>last_position</code> in order to reach the tangent point.</li>
<li>Finally, let the point mass's new <code>position</code> be its <code>last_position</code> adjusted by the above correction vector, scaled down by friction (i.e. scaled by (1 - f)).</li>
</ol>

<h4>Test your implementation</h4>

<pre><code>./clothsim -f ../scene/sphere.json
</code></pre>

<p>You should see your cloth fall on a sphere and drape itself over it before coming to rest.</p>

<p><center>
<img src="https://cs184.eecs.berkeley.edu/cs184_sp17_content/article_images/25_6.jpg" width="800px" />
</center></p>

<h3>3.2: Handling collisions with planes</h3>

<p>Before writing any code, look at the struct definition for a plane in <em>collision/plane.h</em>.</p>

<p>Implement <code>Plane::collide</code>, which takes in a point mass and adjusts its position if it is "inside" the plane, which we define to be when the point moves from one side of the plane to the other in the last time step. If the point mass crosses over, then we "bump" it back up to the side of the surface it originated from:</p>

<ol>
<li>Compute where the point mass should have intersected the plane, if it had travelled in a straight line from its <code>position</code> towards the plane. Call this the tangent point.</li>
<li>Compute the correction vector needed to be applied to the point mass's <code>last_position</code> in order to reach a point slightly above the tangent point, on the same side of the plane that the point mass was before crossing over. We have provided a small constant <code>SURFACE_OFFSET</code> for this small displacement.</li>
<li>Finally, let the point mass's new <code>position</code> be its <code>last_position</code> adjusted by the above correction vector, scaled down by friction (i.e. scaled by (1 - f)).</li>
</ol>

<h4>Test your implementation</h4>

<pre><code>./clothsim -f ../scene/plane.json
</code></pre>

<p>You should see your cloth fall slowly onto the plane and stop at its surface.</p>

<p><center>
<img src="https://cs184.eecs.berkeley.edu/cs184_sp17_content/article_images/25_2.jpg" width="800px" />
</center></p>

<h2>Part 4: Handling self-collisions (BONUS)</h2>

<p>One thing that our implementation currently fails to handle is cloth self-collision. As a result, if we have a scene in which the cloth falls on itself or otherwise folds on itself, the cloth will clip through and behave strangely. You may have seen this type of issue before in video games.</p>

<p>Try it for yourself without any self-collision code:</p>

<pre><code>./clothsim -f ../scene/selfCollision.json
</code></pre>

<p>The cloth ignores itself and falls onto the plane!</p>

<p>To solve this, we will implement cloth self-collision. The naive method of doing this is to loop through all pairs of point masses, compute the distance between them, and then apply a modifying force to the two point masses if they are within some threshold distance apart. However, this O(n^2) solution is too inefficient for real-time simulations, especially as the cloth gets more complex and larger.</p>

<p>Instead, we will implement spatial hashing. At each time step, we build a hash table that maps a float to a <code>vector&lt;PointMass *&gt;</code>, which is stored as <code>map</code> in the <code>Cloth</code> struct. The float uniquely represents a 3D box volume in the scene and the <code>vector&lt;PointMass *&gt;</code> contains all of the point masses that are in that 3D box volume. Once the map is built, we simply have to loop through the point masses, look up (using the hash table) the point masses that it shares the same 3D volume with, and then apply a repulsive collision force if any pair of point masses are too close to each other.</p>

<p>Complete the <code>Cloth::hash_position</code>, <code>Cloth::build_spatial_map</code>, and <code>Cloth::self_collide</code> methods.</p>

<h3>4.1: <code>Cloth::hash_position</code></h3>

<p><code>Cloth::hash_position</code> takes a point mass's position and uniquely map it to a float that represents a specific 3D box volume. One way to do this is effectively partition the 3D space into 3D boxes with dimensions w * h * t where w = <code>3 * width / num_width_points</code>, h = <code>3 * height / num_height_points</code>, and t = max(w, h). (Side note: The constant <code>3</code> here is somewhat empirically chosen to improve the accuracy of the spatial hashing algorithm.) Then, take the position and truncate its coordinates to the closest 3D box (<strong>hint:</strong> think modulo). Using these new coordinates, compute a unique number that corresponds to those 3D coordinates and return it. This will be used as the unique key in our hash table.</p>

<h3>4.2: <code>Cloth::build_spatial_map</code></h3>

<p><code>Cloth::build_spatial_map</code> should loop over all point masses and use the <code>Cloth::hash_position</code> method to populate the <code>map</code> as described above.</p>

<h3>4.3: <code>Cloth::self_collide</code></h3>

<p><code>Cloth::self_collide</code> takes in a point mass and looks up potential candidates for collision using the hash table. For each pair between the point mass and a candidate point mass, determine whether they are within 2 * thickness distance apart. If so, compute a correction vector that can be applied to the point mass (not the candidate one) such that the pair would be 2 * thickness distance apart. The final correction vector to the point mass's position is the average of all of these pairwise correction vectors, scaled down by <code>simulation_steps</code> (this helps improve accuracy by reducing the potential number of sudden position corrections). <strong>Make sure to not collide a point mass with itself!</strong></p>

<h3>Test your implementation</h3>

<pre><code>./clothsim -f ../scene/selfCollision.json
</code></pre>

<p>You should see your cloth folding on itself rather than clipping through itself as it falls to the ground. Yay!</p>

<p>However, you may notice that your cloth will continue to flatten itself out over time rather than coming to a more natural, realistic stop. (In real life, damping factors like friction, heat loss, etc. all contribute to net energy loss in the cloth system.) This is because even in a "resting state" on the ground plane, the cloth's point masses will continue to repel each other due to lack of damping spring forces in our model (which is more difficult to do physically accurately using Verlet integration).  Don't worry if your cloth is exhibiting this behavior! What's important is that your cloth does not clip through itself and exhibits folding on itself.</p>

<p><center>
<img src="https://cs184.eecs.berkeley.edu/cs184_sp17_content/article_images/25_4.jpg" width="800px" />
</center></p>

<p><center>
<img src="https://cs184.eecs.berkeley.edu/cs184_sp17_content/article_images/25_3.jpg" width="800px" />
</center></p>

<h2>Part 5: Additional cloth simulation features! (BONUS)</h2>

<p>For this Assignment, try adding some additional technical features to further improve your cloth simulation! Feel free to browse recently published research papers, or check out some of the following suggested ideas:</p>

<ul>
<li>Add wind (which is a spatially varying force)</li>
<li>More robust self-collisions than spatial hashing (e.g. use a axis-aligned bounding box hierarchy to figure out where parts of the cloth intersect)</li>
<li>Better rendering of the cloth (e.g. different shaders than Phong shading)</li>
<li>Add the ability to move objects using the GUI around in the scene and have them collide with objects (could move the cloth, or move the sphere or plane, etc.)</li>
<li>Add other 3D primitives and show that your cloth properly collides with them</li>
</ul>

<p>For extra credit, you may need to modify other parts of the simulation infrastructure as well as add your own source files. Exercise your creativity and feel free to run all over the skeleton!</p></div>

</div>
</div>
</div>
</body>
</html>