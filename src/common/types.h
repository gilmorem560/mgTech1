/*
 * types - commonly used types
 */ 
#ifndef __TYPES_H__
#define __TYPES_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
	
typedef struct vect2f {
	float x;
	float y;
} vect2f;

typedef struct vect3f {
	float x;
	float y;
	float z;
} vect3f;

typedef vect2f point2f;
typedef vect2f ang2f;
typedef vect3f point3f;
typedef vect3f ang3f;
	
#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif /* __TYPES_H__ */
