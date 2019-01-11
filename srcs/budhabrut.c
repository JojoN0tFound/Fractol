/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   budhabrut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:25:26 by jquivogn          #+#    #+#             */
/*   Updated: 2019/01/11 17:34:50 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

définir x1 = -2.1
définir x2 = 0.6
définir y1 = -1.2
définir y2 = 1.2
définir zoom = 100
définir iteration_rouge = 100
définir iteration_vert = 1000
définir iteration_bleu = 10000
définir iteration_max = max(iteration_rouge, iteration_vert, iteration_bleu)

définir image_x = (x2 - x1) * zoom
définir image_y = (y2 - y1) * zoom

définir pixels_rouge comme un tableau 2D de image_x cases sur image_y cases avec toutes les cases initialisés à 0
définir pixels_vert comme un tableau 2D de image_x cases sur image_y cases avec toutes les cases initialisés à 0
définir pixels_bleu comme un tableau 2D de image_x cases sur image_y cases avec toutes les cases initialisés à 0

// en théorie, on devrait faire une seul boucle dans laquelle on devrait prendre les coordonnés (x; y) au hasard.
Pour x = 0 tant que x < image_x par pas de 1
    Pour y = 0 tant que y < image_y par pas de 1
        définir c_r = x / zoom + x1
        définir c_i = y / zoom + y1
        définir z_r = 0
        définir z_i = 0
        définir i = 0
        définir tmp_pixels comme une liste de coordonnées

        Faire
            définir tmp = z_r
            z_r = z_r*z_r - z_i*z_i + c_r
            z_i = 2*z_i*tmp + c_i
            i = i+1
            ajouter les coordonnées ((z_r-x1)*zoom; (z_i-y1)*zoom) au tableau tmp_pixels
        Tant que z_r*z_r + z_i*z_i < 4 et i < iteration_max

        si i < iteration_rouge
            Pour les iteration_rouge premières valeurs pixel de tmp_pixels
                si la case pixels_rouge[pixel[0]][pixel[1]] existe
                    on incrémente la case en question
                finSi
            finPour
        finSi
        si i < iteration_vert
            Pour les iteration_vert premières valeurs pixel de tmp_pixels
                si la case pixels_vert[pixel[0]][pixel[1]] existe
                    on incrémente la case en question
                finSi
            finPour
        finSi
        si i < iteration_bleu
            Pour les iteration_bleu premières valeurs pixel de tmp_pixels
                si la case pixels_bleu[pixel[0]][pixel[1]] existe
                    on incrémente la case en question
                finSi
            finPour
        finSi
    finPour
finPour

Pour chaque pixel de coordonnée (x; y) de l'image
    Dessiner le pixel de coordonnée (x; y) avec la couleur rgb(min(pixels_rouge[x][y], 255), min(pixels_vert[x][y], 255), min(pixels_bleu[x][y], 255))
finPour