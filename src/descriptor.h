/*****************************************************************************
 * descriptor.h
 * Copyright (C) 2001-2010 VideoLAN
 * $Id: descriptor.h,v 1.5 2002/05/08 13:00:40 bozo Exp $
 *
 * Authors: Arnaud de Bossoreille de Ribou <bozo@via.ecp.fr>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *****************************************************************************/

/*!
 * \file <descriptor.h>
 * \author Arnaud de Bossoreille de Ribou <bozo@via.ecp.fr>
 * \brief Common descriptor tools.
 *
 * Descriptor structure and its Manipulation tools.
 *
 * NOTE: Descriptor generators and decoder functions return a pointer on success
 * and NULL on error. They do not use a dvbpsi_t handle as first argument.
 */

#ifndef _DVBPSI_DESCRIPTOR_H_
#define _DVBPSI_DESCRIPTOR_H_

#ifdef __cplusplus
extern "C" {
#endif


/*****************************************************************************
 * dvbpsi_descriptor_t
 *****************************************************************************/
/*!
 * \struct dvbpsi_descriptor_s
 * \brief Descriptor structure.
 *
 * This structure is used to store a descriptor.
 * (ISO/IEC 13818-1 section 2.6).
 */
/*!
 * \typedef struct dvbpsi_descriptor_s dvbpsi_descriptor_t
 * \brief dvbpsi_descriptor_t type definition.
 */
typedef struct dvbpsi_descriptor_s
{
  uint8_t                       i_tag;          /*!< descriptor_tag */
  uint8_t                       i_length;       /*!< descriptor_length */

  uint8_t *                     p_data;         /*!< content */

  struct dvbpsi_descriptor_s *  p_next;         /*!< next element of
                                                     the list */

  void *                        p_decoded;      /*!< decoded descriptor */

} dvbpsi_descriptor_t;

/*****************************************************************************
 * dvbpsi_NewDescriptor
 *****************************************************************************/
/*!
 * \fn dvbpsi_descriptor_t* dvbpsi_NewDescriptor(uint8_t i_tag,
                                                 uint8_t i_length,
                                                 uint8_t* p_data)
 * \brief Creation of a new dvbpsi_descriptor_t structure.
 * \param i_tag descriptor's tag
 * \param i_length descriptor's length
 * \param p_data descriptor's data
 * \return a pointer to the descriptor.
 */
dvbpsi_descriptor_t* dvbpsi_NewDescriptor(uint8_t i_tag, uint8_t i_length,
                                          uint8_t* p_data);


/*****************************************************************************
 * dvbpsi_DeleteDescriptors
 *****************************************************************************/
/*!
 * \fn void dvbpsi_DeleteDescriptors(dvbpsi_descriptor_t* p_descriptor)
 * \brief Destruction of a dvbpsi_descriptor_t structure.
 * \param p_descriptor pointer to the first descriptor structure
 * \return nothing.
 */
void dvbpsi_DeleteDescriptors(dvbpsi_descriptor_t* p_descriptor);

/*****************************************************************************
 * dvbpsi_CanDecodeAsDescriptor
 *****************************************************************************/
/*!
 * \fn bool dvbpsi_CanDecodeAsDescriptor(dvbpsi_descriptor_t *p_descriptor, const uint8_t i_tag);
 * \brief Checks if descriptor tag matches.
 * \param p_descriptor pointer to descriptor allocated with @see dvbpsi_NewDescriptor
 * \param i_tag descriptor tag to evaluate against
 * \return true if descriptor can be decoded, false if not.
 */
bool dvbpsi_CanDecodeAsDescriptor(dvbpsi_descriptor_t *p_descriptor, const uint8_t i_tag);

/*****************************************************************************
 * dvbpsi_IsDescriptorDecoded
 *****************************************************************************/
/*!
 * \fn bool dvbpsi_IsDescriptorDecoded(dvbpsi_descriptor_t *p_descriptor);
 * \brief Checks if descriptor was already decoded.
 * \param p_descriptor pointer to descriptor allocated with @see dvbpsi_NewDescriptor
 * \return true if descriptor can be decoded, false if already decoded.
 */
bool dvbpsi_IsDescriptorDecoded(dvbpsi_descriptor_t *p_descriptor);

/*****************************************************************************
 * dvbpsi_DuplicateDecodedDescriptor
 *****************************************************************************/
/*!
 * \fn void *dvbpsi_DuplicateDecodedDescriptor(void *p_decoded, ssize_t i_size);
 * \brief Duplicate a decoded descriptor. The caller is responsible for releasing the associated memory..
 * \param p_decoded pointer to decoded descriptor obatained with dvbpsi_Decode* function
 * \param i_size the sizeof decoded descriptor
 * \return pointer to duplicated descriptor, NULL on error.
 */
void *dvbpsi_DuplicateDecodedDescriptor(void *p_decoded, ssize_t i_size);

#ifdef __cplusplus
};
#endif

#else
#error "Multiple inclusions of descriptor.h"
#endif

