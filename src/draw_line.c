/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 21:57:42 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/20 22:48:56 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// void	draw_line(t_env e, t_pts **pts, int l, int c)
// {
// 	int xinc;
// 	int yinc;
// 	int dx;
// 	int dy;
//
// 	dx = pts[l][c + 1].x - pts[l][c].x;
// 	dy = pts[l][c + 1].y - pts[l][c].y;
// }
//
// void ligne(int xi,int yi,int xf,int yf) {
//   int dx,dy,i,xinc,yinc,cumul,x,y ;
//   x = xi ;
//   y = yi ;
//   dx = xf - xi ;
//   dy = yf - yi ;
//   xinc = ( dx > 0 ) ? 1 : -1 ;
//   yinc = ( dy > 0 ) ? 1 : -1 ;
//   dx = abs(dx) ;
//   dy = abs(dy) ;
//   allume_pixel(x,y) ;
//   if ( dx > dy ) {
//     cumul = dx / 2 ;
//     for ( i = 1 ; i <= dx ; i++ ) {
//       x += xinc ;
//       cumul += dy ;
//       if ( cumul >= dx ) {
//         cumul -= dx ;
//         y += yinc ; }
//       allume_pixel(x,y) ; } }
//     else {
//     cumul = dy / 2 ;
//     for ( i = 1 ; i <= dy ; i++ ) {
//       y += yinc ;
//       cumul += dx ;
//       if ( cumul >= dy ) {
//         cumul -= dy ;
//         x += xinc ; }
//       allume_pixel(x,y) ; } }
// }
