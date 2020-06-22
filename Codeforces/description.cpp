
class point3d (x,y,z)

class       object
         /     |      \
  sphere     triangle   tiles
 /    \        |         |
center 3dpt  3 3dpts    tile_size

class ray (origin and direction given)



object functions:
1. get normal at specific point
2. intersection with a specific ray
3. draw in OpenGL etc
4. print (for debug purspose), getter, setter etc




global functions:
1. read input and prepare objects
        get your hands dirty.

2. capture function (called after pressing '0')
        prepare the image and fix height-width
        prepare the plane upon which the image you want to project
        pass different rays that start from *eye* and go through different pixels. iterate through the pixels (maybe 786*786 2d loop)

3. find_intensity function that takes a ray

        iterates through objects and find intersection_points
            for each of the lights, checks whether light can come at this point and finds intensity
        counts diffuse, specular reflections




task sequence:

1. read input
2. draw the objects (object fucntion)

3. complete the capture function that calls the find intensity function

4. Iterate through the objects to find nearest object and its hitpoint
    a. upon intersection, take the object color only and put it into the corresponding pixel. this ensures 50% marks.

    b. add ambient light effect, without iterating over the light sources (darkens the picture)
    c. for every light source, add diffuse and specular components. calculations are explained in earlier videos

    *** intensity due to specular reflection depends on light intensity [ (r,g,b)=(1,1,1) assumed ] ,
        where ambient and diffuse reflection is caused by object colour. ***

5.  add reflection with a recursive call to this function. extra parameter for recursion level needed.
    use the intersection point as the new eye and the reflection direction as the new ray direction.
    use the get_normal for an object (mentioned above) to find reflected direction


Good luck!
