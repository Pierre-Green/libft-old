/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:39:48 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/10 19:05:11 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_VEC_H
# define FT_MATH_VEC_H
# include <stdint.h>

/*
** Types:
**
** Dynamic type vector 2D
*/
typedef struct			s_dvec2
{
	void				*x;
	void				*y;
	uint8_t				size;
	struct s_vec2_i8    (*sum)(struct s_vec2_i8, struct s_vec2_i8);
	struct s_vec2_i8    (*minus)(struct s_vec2_i8, struct s_vec2_i8);
	struct s_vec2_i8    (*product1)(struct s_vec2_i8, int8_t);
	int8_t              (*product2)(struct s_vec2_i8, struct s_vec2_i8);
	int8_t              (*norm)(struct s_vec2_i8);
	struct s_vec2_i8    (*normalize)(struct s_vec2_i8);
	int8_t              (*length)(struct s_vec2_i8);
	int8_t              (*at)(struct s_vec2_i8, uint8_t);
	char                *(*tostring)(struct s_vec2_i8);
}						t_dvec2;

/*
** Integer 2D vector types
*/
typedef struct	        s_vec2_i8
{
	int8_t              x;
	int8_t              y;
	struct s_vec2_i8    (*sum)(struct s_vec2_i8, struct s_vec2_i8);
	struct s_vec2_i8    (*minus)(struct s_vec2_i8, struct s_vec2_i8);
	struct s_vec2_i8    (*product1)(struct s_vec2_i8, int8_t);
	int8_t              (*product2)(struct s_vec2_i8, struct s_vec2_i8);
	int8_t              (*norm)(struct s_vec2_i8);
	struct s_vec2_i8    (*normalize)(struct s_vec2_i8);
	int8_t              (*length)(struct s_vec2_i8);
	int8_t              (*at)(struct s_vec2_i8, uint8_t);
	char                *(*tostring)(struct s_vec2_i8);
}				        t_vec2_i8;

typedef struct	        s_vec2_i16
{
	int16_t             x;
	int16_t             y;
	struct s_vec2_i16   (*sum)(struct s_vec2_i16, struct s_vec2_i16);
	struct s_vec2_i16   (*minus)(struct s_vec2_i16, struct s_vec2_i16);
	struct s_vec2_i16   (*product1)(struct s_vec2_i16, int16_t);
	int16_t             (*product2)(struct s_vec2_i16, struct s_vec2_i16);
	int16_t             (*norm)(struct s_vec2_i16);
	struct s_vec2_i16   (*normalize)(struct s_vec2_i16);
	int16_t             (*length)(struct s_vec2_i16);
	int16_t             (*at)(struct s_vec2_i16, uint8_t);
	char                *(*tostring)(struct s_vec2_i16);
}				        t_vec2_i16;

typedef struct	        s_vec2_i32
{
	int32_t             x;
	int32_t             y;
	struct s_vec2_i32   (*sum)(struct s_vec2_i32, struct s_vec2_i32);
	struct s_vec2_i32   (*minus)(struct s_vec2_i32, struct s_vec2_i32);
	struct s_vec2_i32   (*product1)(struct s_vec2_i32, int32_t);
	int32_t             (*product2)(struct s_vec2_i32, struct s_vec2_i32);
	int32_t             (*norm)(struct s_vec2_i32);
	struct s_vec2_i32   (*normalize)(struct s_vec2_i32);
	int32_t             (*length)(struct s_vec2_i32);
	int32_t             (*at)(struct s_vec2_i32, uint8_t);
	char                *(*tostring)(struct s_vec2_i32);
}				        t_vec2_i32;

/*
** Floating point 2D vector types
*/
typedef struct	s_vec2_f
{
	float				x;
	float				y;
	struct s_vec2_f   	(*sum)(struct s_vec2_f, struct s_vec2_f);
	struct s_vec2_f  	(*minus)(struct s_vec2_f, struct s_vec2_f);
	struct s_vec2_f   	(*product1)(struct s_vec2_f, float);
	float	            (*product2)(struct s_vec2_f, struct s_vec2_f);
	float             	(*norm)(struct s_vec2_f);
	struct s_vec2_f	    (*normalize)(struct s_vec2_f);
	float 	            (*length)(struct s_vec2_f);
	float               (*at)(struct s_vec2_f, uint8_t);
	char                *(*tostring)(struct s_vec2_f);
}						t_vec2_f;


typedef struct	s_vec2_d
{
	double				x;
	double				y;
	struct s_vec2_d   	(*sum)(struct s_vec2_d, struct s_vec2_d);
	struct s_vec2_d  	(*minus)(struct s_vec2_d, struct s_vec2_d);
	struct s_vec2_d   	(*product1)(struct s_vec2_d, double);
	double	            (*product2)(struct s_vec2_d, struct s_vec2_d);
	double              (*norm)(struct s_vec2_d);
	struct s_vec2_d	    (*normalize)(struct s_vec2_d);
	double 	            (*length)(struct s_vec2_d);
	double              (*at)(struct s_vec2_d, uint8_t);
	char                *(*tostring)(struct s_vec2_d);
}						t_vec2_d;

typedef struct	s_vec2_ld
{
	long double			x;
	long double			y;
	struct s_vec2_ld    (*sum)(struct s_vec2_ld, struct s_vec2_ld);
	struct s_vec2_ld  	(*minus)(struct s_vec2_ld, struct s_vec2_ld);
	struct s_vec2_ld   	(*product1)(struct s_vec2_ld, long double);
	long double	        (*product2)(struct s_vec2_ld, struct s_vec2_ld);
	long double         (*norm)(struct s_vec2_ld);
	struct s_vec2_ld	(*normalize)(struct s_vec2_ld);
	long double 	    (*length)(struct s_vec2_ld);
	long double         (*at)(struct s_vec2_ld, uint8_t);
	char                *(*tostring)(struct s_vec2_ld);
}						t_vec2_ld;

/*
** Dynamic type vector 2D
*/
typedef struct			s_dvec3
{
	void				*x;
	void				*y;
	void				*z;
	uint8_t				size;
	struct s_vec2_i8    (*sum)(struct s_vec2_i8, struct s_vec2_i8);
	struct s_vec2_i8    (*minus)(struct s_vec2_i8, struct s_vec2_i8);
	struct s_vec2_i8    (*product1)(struct s_vec2_i8, int8_t);
	int8_t              (*product2)(struct s_vec2_i8, struct s_vec2_i8);
	int8_t              (*norm)(struct s_vec2_i8);
	struct s_vec2_i8    (*normalize)(struct s_vec2_i8);
	int8_t              (*length)(struct s_vec2_i8);
	int8_t              (*at)(struct s_vec2_i8, uint8_t);
	char                *(*tostring)(struct s_vec2_i8);
}						t_dvec3;


/*
** Integer 3D vector types
*/
typedef struct	        s_vec3_i8
{
	int8_t              x;
	int8_t              y;
	int8_t              z;
	struct s_vec3_i8    (*sum)(struct s_vec3_i8, struct s_vec3_i8);
	struct s_vec3_i8    (*minus)(struct s_vec3_i8, struct s_vec3_i8);
	struct s_vec3_i8    (*product1)(struct s_vec3_i8, int8_t);
	int8_t              (*product3)(struct s_vec3_i8, struct s_vec3_i8);
	int8_t              (*norm)(struct s_vec3_i8);
	struct s_vec3_i8    (*normalize)(struct s_vec3_i8);
	int8_t              (*length)(struct s_vec3_i8);
	int8_t              (*at)(struct s_vec3_i8, uint8_t);
	char                *(*tostring)(struct s_vec3_i8);
}				        t_vec3_i8;

typedef struct      	s_vec3_i16
{
	int16_t             x;
	int16_t             y;
	int16_t             z;
	struct s_vec3_i16   (*sum)(struct s_vec3_i16, struct s_vec3_i16);
	struct s_vec3_i16   (*minus)(struct s_vec3_i16, struct s_vec3_i16);
	struct s_vec3_i16   (*product1)(struct s_vec3_i16, int16_t);
	int16_t             (*product3)(struct s_vec3_i16, struct s_vec3_i16);
	int16_t             (*norm)(struct s_vec3_i16);
	struct s_vec3_i16   (*normalize)(struct s_vec3_i16);
	int16_t             (*length)(struct s_vec3_i16);
	int16_t             (*at)(struct s_vec3_i16, uint8_t);
	char                *(*tostring)(struct s_vec3_i16);
}			        	t_vec3_i16;

typedef struct			s_vec3_i32
{
	int32_t				x;
	int32_t				y;
	int32_t				z;
	struct s_vec3_i32   (*sum)(struct s_vec3_i32, struct s_vec3_i32);
	struct s_vec3_i32   (*minus)(struct s_vec3_i32, struct s_vec3_i32);
	struct s_vec3_i32   (*product1)(struct s_vec3_i32, int32_t);
	int32_t             (*product3)(struct s_vec3_i32, struct s_vec3_i32);
	int32_t             (*norm)(struct s_vec3_i32);
	struct s_vec3_i32   (*normalize)(struct s_vec3_i32);
	int32_t             (*length)(struct s_vec3_i32);
	int32_t             (*at)(struct s_vec3_i32, uint8_t);
	char                *(*tostring)(struct s_vec3_i32);
}						t_vec3_i32;

/*
** Floating point 3D vector types
*/
typedef struct	s_vec3_f
{
	float				x;
	float				y;
	float				z;
	struct s_vec3_f     (*sum)(struct s_vec3_f, struct s_vec3_f);
	struct s_vec3_f     (*minus)(struct s_vec3_f, struct s_vec3_f);
	struct s_vec3_f   	(*product1)(struct s_vec3_f, float);
	float               (*product3)(struct s_vec3_f, struct s_vec3_f);
	float               (*norm)(struct s_vec3_f);
	struct s_vec3_f     (*normalize)(struct s_vec3_f);
	float               (*length)(struct s_vec3_f);
	float               (*at)(struct s_vec3_f, uint8_t);
	char                *(*tostring)(struct s_vec3_f);
}						t_vec3_f;

typedef struct	s_vec3_d
{
	double				x;
	double				y;
	double				z;
	struct s_vec3_d     (*sum)(struct s_vec3_d, struct s_vec3_d);
	struct s_vec3_d     (*minus)(struct s_vec3_d, struct s_vec3_d);
	struct s_vec3_d   	(*product1)(struct s_vec3_d, double);
	double              (*product3)(struct s_vec3_d, struct s_vec3_d);
	double              (*norm)(struct s_vec3_d);
	struct s_vec3_d     (*normalize)(struct s_vec3_d);
	double              (*length)(struct s_vec3_d);
	double              (*at)(struct s_vec3_d, uint8_t);
	char                *(*tostring)(struct s_vec3_d);
}						t_vec3_d;

typedef struct	s_vec3_ld
{
	long double			x;
	long double			y;
	long double			z;
	struct s_vec3_ld    (*sum)(struct s_vec3_ld, struct s_vec3_ld);
	struct s_vec3_ld    (*minus)(struct s_vec3_ld, struct s_vec3_ld);
	struct s_vec3_ld   	(*product1)(struct s_vec3_ld, long double);
	long double         (*product3)(struct s_vec3_ld, struct s_vec3_ld);
	long double         (*norm)(struct s_vec3_ld);
	struct s_vec3_ld    (*normalize)(struct s_vec3_ld);
	long double         (*length)(struct s_vec3_ld);
	long double         (*at)(struct s_vec3_ld, uint8_t);
	char                (*tostring)(struct s_vec3_ld);
}						t_vec3_ld;

/*
** Prototypes:
**
** vec2_i8
*/
t_vec2_i8               ft_init0_vec2_i8();

t_vec2_i8               ft_init1_vec2_i8(int8_t a);

t_vec2_i8               ft_init2_vec2_i8(int8_t x, int8_t y);

t_vec2_i8               ft_vec2_i8_sum(t_vec2_i8 self, t_vec2_i8 vec);

t_vec2_i8               ft_vec2_i8_minus(t_vec2_i8 self, t_vec2_i8 vec);

t_vec2_i8               ft_vec2_i8_product1(t_vec2_i8 self, int8_t a);

int8_t                  ft_vec2_i8_product2(t_vec2_i8 self, t_vec2_i8 vec);

int8_t                  ft_vec2_i8_norm(t_vec2_i8 self);

int8_t                  ft_vec2_i8_length(t_vec2_i8 self);

int8_t                  ft_vec2_i8_at(t_vec2_i8 self, uint8_t i);

char                    *ft_vec2_i8_tostring(t_vec2_i8 self);

int8_t                  ft_vec2_i8_crossproduct(t_vec2_i8 self, t_vec2_i8 vec);

t_vec2_i8               ft_vec2_i8_normalize(t_vec2_i8 self);

/*
** vec2_i16
*/
t_vec2_i16              ft_init0_vec2_i16();

t_vec2_i16              ft_init1_vec2_i16(int16_t a);

t_vec2_i16              ft_init2_vec2_i16(int16_t x, int16_t y);

t_vec2_i16              ft_vec2_i16_sum(t_vec2_i16 self, t_vec2_i16 vec);

t_vec2_i16              ft_vec2_i16_minus(t_vec2_i16 self, t_vec2_i16 vec);

t_vec2_i16              ft_vec2_i16_product1(t_vec2_i16 self, int16_t a);

int16_t                 ft_vec2_i16_product2(t_vec2_i16 self, t_vec2_i16 vec);

int16_t                 ft_vec2_i16_norm(t_vec2_i16 self);

int16_t                 ft_vec2_i16_length(t_vec2_i16 self);

int16_t                 ft_vec2_i16_at(t_vec2_i16 self, uint8_t i);

char                    *ft_vec2_i16_tostring(t_vec2_i16 self);

int16_t                 ft_vec2_i16_crossproduct(t_vec2_i16 self, t_vec2_i16 vec);

t_vec2_i16              ft_vec2_i16_normalize(t_vec2_i16 self);

/*
** vec2_i32
*/
t_vec2_i32              ft_init0_vec2_i32();

t_vec2_i32              ft_init1_vec2_i32(int32_t a);

t_vec2_i32              ft_init2_vec2_i32(int32_t x, int32_t y);

t_vec2_i32              ft_vec2_i32_sum(t_vec2_i32 self, t_vec2_i32 vec);

t_vec2_i32              ft_vec2_i32_minus(t_vec2_i32 self, t_vec2_i32 vec);

t_vec2_i32              ft_vec2_i32_product1(t_vec2_i32 self, int32_t a);

int32_t                 ft_vec2_i32_product2(t_vec2_i32 self, t_vec2_i32 vec);

int32_t                 ft_vec2_i32_norm(t_vec2_i32 self);

int32_t                 ft_vec2_i32_length(t_vec2_i32 self);

int32_t                 ft_vec2_i32_at(t_vec2_i32 self, uint8_t i);

char                    *ft_vec2_i32_tostring(t_vec2_i32 self);

int32_t                 ft_vec2_i32_crossproduct(t_vec2_i32 self, t_vec2_i32 vec);

t_vec2_i32              ft_vec2_i32_normalize(t_vec2_i32 self);

/*
** vec2_f
*/
t_vec2_f              	ft_init0_vec2_f();

t_vec2_f              	ft_init1_vec2_f(float a);

t_vec2_f             	ft_init2_vec2_f(float x, float y);

t_vec2_f              	ft_vec2_f_sum(t_vec2_f self, t_vec2_f vec);

t_vec2_f              	ft_vec2_f_minus(t_vec2_f self, t_vec2_f vec);

t_vec2_f              	ft_vec2_f_product1(t_vec2_f self, float a);

float                	ft_vec2_f_product2(t_vec2_f self, t_vec2_f vec);

float                 	ft_vec2_f_norm(t_vec2_f self);

float                 	ft_vec2_f_length(t_vec2_f self);

float                 	ft_vec2_f_at(t_vec2_f self, uint8_t i);

char                  	*ft_vec2_f_tostring(t_vec2_f self);

float                 	ft_vec2_f_crossproduct(t_vec2_f self, t_vec2_f vec);

t_vec2_f              	ft_vec2_f_normalize(t_vec2_f self);

/*
** vec2_d
*/
t_vec2_d              	ft_init0_vec2_d();

t_vec2_d              	ft_init1_vec2_d(double a);

t_vec2_d             	ft_init2_vec2_d(double x, double y);

t_vec2_d              	ft_vec2_d_sum(t_vec2_d self, t_vec2_d vec);

t_vec2_d              	ft_vec2_d_minus(t_vec2_d self, t_vec2_d vec);

t_vec2_d              	ft_vec2_d_product1(t_vec2_d self, float a);

double                	ft_vec2_d_product2(t_vec2_d self, t_vec2_d vec);

double                 	ft_vec2_d_norm(t_vec2_d self);

double                 	ft_vec2_d_length(t_vec2_d self);

double                 	ft_vec2_d_at(t_vec2_d self, uint8_t i);

char                  	*ft_vec2_d_tostring(t_vec2_d self);

double                 	ft_vec2_d_crossproduct(t_vec2_d self, t_vec2_d vec);

t_vec2_d              	ft_vec2_d_normalize(t_vec2_d self);

/*
** vec2_ld
*/
t_vec2_ld              	ft_init0_vec2_ld();

t_vec2_ld              	ft_init1_vec2_ld(long double a);

t_vec2_ld             	ft_init2_vec2_ld(long double x, long double y);

t_vec2_ld              	ft_vec2_ld_sum(t_vec2_ld self, t_vec2_ld vec);

t_vec2_ld              	ft_vec2_ld_minus(t_vec2_ld self, t_vec2_ld vec);

t_vec2_ld              	ft_vec2_ld_product1(t_vec2_ld self, float a);

long double             ft_vec2_ld_product2(t_vec2_ld self, t_vec2_ld vec);

long double             ft_vec2_ld_norm(t_vec2_ld self);

long double 			ft_vec2_ld_length(t_vec2_ld self);

long double             ft_vec2_ld_at(t_vec2_ld self, uint8_t i);

char                  	*ft_vec2_ld_tostring(t_vec2_ld self);

long double             ft_vec2_ld_crossproduct(t_vec2_ld self, t_vec2_ld vec);

t_vec2_ld              	ft_vec2_ld_normalize(t_vec2_ld self);

/*
** vec3_i8
*/
t_vec3_i8               ft_init0_vec3_i8();

t_vec3_i8               ft_init1_vec3_i8(int8_t a);

t_vec3_i8               ft_init3_vec3_i8(int8_t x, int8_t y, int8_t z);

t_vec3_i8               ft_vec3_i8_sum(t_vec3_i8 self, t_vec3_i8 vec);

t_vec3_i8               ft_vec3_i8_minus(t_vec3_i8 self, t_vec3_i8 vec);

t_vec3_i8               ft_vec3_i8_product1(t_vec3_i8 self, int8_t a);

int8_t                  ft_vec3_i8_product3(t_vec3_i8 self, t_vec3_i8 vec);

int8_t                  ft_vec3_i8_norm(t_vec3_i8 self);

int8_t                  ft_vec3_i8_length(t_vec3_i8 self);

int8_t                  ft_vec3_i8_at(t_vec3_i8 self, uint8_t i);

char                    *ft_vec3_i8_tostring(t_vec3_i8 self);

int8_t                  ft_vec3_i8_crossproduct(t_vec3_i8 self, t_vec3_i8 vec);

t_vec3_i8               ft_vec3_i8_normalize(t_vec3_i8 self);

/*
** vec3_i16
*/
t_vec3_i16				ft_init0_vec3_i16();

t_vec3_i16				ft_init1_vec3_i16(int16_t a);

t_vec3_i16				ft_init3_vec3_i16(int16_t x, int16_t y, int16_t z);

t_vec3_i16       		ft_vec3_i16_sum(t_vec3_i16 self, t_vec3_i16 vec);

t_vec3_i16              ft_vec3_i16_minus(t_vec3_i16 self, t_vec3_i16 vec);

t_vec3_i16              ft_vec3_i16_product1(t_vec3_i16 self, int16_t a);

int16_t                 ft_vec3_i16_product3(t_vec3_i16 self, t_vec3_i16 vec);

int16_t                 ft_vec3_i16_norm(t_vec3_i16 self);

int16_t                 ft_vec3_i16_length(t_vec3_i16 self);

int16_t                 ft_vec3_i16_at(t_vec3_i16 self, uint8_t i);

char                    *ft_vec3_i16_tostring(t_vec3_i16 self);

int16_t                 ft_vec3_i16_crossproduct(t_vec3_i16 self, t_vec3_i16 vec);

t_vec3_i16              ft_vec3_i16_normalize(t_vec3_i16 self);

/*
** vec3_i32
*/
t_vec3_i32       		ft_init0_vec3_i32();

t_vec3_i32       		ft_init1_vec3_i32(int32_t a);

t_vec3_i32       		ft_init3_vec3_i32(int32_t x, int32_t y, int32_t z);

t_vec3_i32              ft_vec3_i32_sum(t_vec3_i32 self, t_vec3_i32 vec);

t_vec3_i32              ft_vec3_i32_minus(t_vec3_i32 self, t_vec3_i32 vec);

t_vec3_i32              ft_vec3_i32_product1(t_vec3_i32 self, int32_t a);

int32_t                 ft_vec3_i32_product3(t_vec3_i32 self, t_vec3_i32 vec);

int32_t                 ft_vec3_i32_norm(t_vec3_i32 self);

int32_t                 ft_vec3_i32_length(t_vec3_i32 self);

int32_t                 ft_vec3_i32_at(t_vec3_i32 self, uint8_t i);

char                    *ft_vec3_i32_tostring(t_vec3_i32 self);

int32_t                 ft_vec3_i32_crossproduct(t_vec3_i32 self, t_vec3_i32 vec);

t_vec3_i32              ft_vec3_i32_normalize(t_vec3_i32 self);

/*
** vec3_f
*/
t_vec3_f              	ft_init0_vec3_f();

t_vec3_f              	ft_init1_vec3_f(float a);

t_vec3_f             	 ft_init3_vec3_f(float x, float y);

t_vec3_f              	ft_vec3_f_sum(t_vec3_f self, t_vec3_f vec);

t_vec3_f              	ft_vec3_f_minus(t_vec3_f self, t_vec3_f vec);

t_vec3_f              	ft_vec3_f_product1(t_vec3_f self, float a);

float                	ft_vec3_f_product3(t_vec3_f self, t_vec3_f vec);

float                 	ft_vec3_f_norm(t_vec3_f self);

float                 	ft_vec3_f_length(t_vec3_f self);

float                 	ft_vec3_f_at(t_vec3_f self, uint8_t i);

char                  	*ft_vec3_f_tostring(t_vec3_f self);

float                 	ft_vec3_f_crossproduct(t_vec3_f self, t_vec3_f vec);

t_vec3_f              	ft_vec3_f_normalize(t_vec3_f self);

/*
** vec3_d
*/
t_vec3_d              	ft_init0_vec3_d();

t_vec3_d              	ft_init1_vec3_d(double a);

t_vec3_d             	ft_init3_vec3_d(double x, double y);

t_vec3_d              	ft_vec3_d_sum(t_vec3_d self, t_vec3_d vec);

t_vec3_d              	ft_vec3_d_minus(t_vec3_d self, t_vec3_d vec);

t_vec3_d              	ft_vec3_d_product1(t_vec3_d self, float a);

double                	ft_vec3_d_product3(t_vec3_d self, t_vec3_d vec);

double                 	ft_vec3_d_norm(t_vec3_d self);

double                 	ft_vec3_d_length(t_vec3_d self);

double                 	ft_vec3_d_at(t_vec3_d self, uint8_t i);

char                  	*ft_vec3_d_tostring(t_vec3_d self);

double                 	ft_vec3_d_crossproduct(t_vec3_d self, t_vec3_d vec);

t_vec3_d              	ft_vec3_d_normalize(t_vec3_d self);

/*
** vec3_ld
*/
t_vec3_ld              	ft_init0_vec3_ld();

t_vec3_ld              	ft_init1_vec3_ld(long double a);

t_vec3_ld             	ft_init3_vec3_ld(long double x, long double y);

t_vec3_ld              	ft_vec3_ld_sum(t_vec3_ld self, t_vec3_ld vec);

t_vec3_ld              	ft_vec3_ld_minus(t_vec3_ld self, t_vec3_ld vec);

t_vec3_ld              	ft_vec3_ld_product1(t_vec3_ld self, float a);

long double             ft_vec3_ld_product3(t_vec3_ld self, t_vec3_ld vec);

long double             ft_vec3_ld_norm(t_vec3_ld self);

long double 			ft_vec3_ld_length(t_vec3_ld self);

long double             ft_vec3_ld_at(t_vec3_ld self, uint8_t i);

char                  	*ft_vec3_ld_tostring(t_vec3_ld self);

long double             ft_vec3_ld_crossproduct(t_vec3_ld self, t_vec3_ld vec);

t_vec3_ld              	ft_vec3_ld_normalize(t_vec3_ld self);

#endif