/*
    This file is part of darktable,
    Copyright (C) 2014-2020 darktable developers.

    darktable is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    darktable is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with darktable.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

struct dt_import_session_t;

struct dt_import_session_t *dt_import_session_new();
void dt_import_session_destroy(struct dt_import_session_t *self);

/** \brief Verify that we use current film and import images into it */
gboolean dt_import_session_ready(struct dt_import_session_t *self);

/** \brief add reference to specified import session */
void dt_import_session_ref(struct dt_import_session_t *self);
/** \brief remove reference to specified import session */
void dt_import_session_unref(struct dt_import_session_t *self);

/** \brief import of current filename to session film roll */
void dt_import_session_import(struct dt_import_session_t *self);

/** \brief set the job code of the specific import session */
void dt_import_session_set_name(struct dt_import_session_t *self, const char *name);

/** \brief override the time for specific import session
    \remark This will override NOW timestamp with a specified one used when expanding ${YEAR} and alike.
*/
void dt_import_session_set_time(struct dt_import_session_t *self, const char *time);

/** \brief set the timestamp for EXIF variables */
void dt_import_session_set_exif_time(struct dt_import_session_t *self, const char *exif_time);

/** \brief set the original filename
    \remark This is used to expand $(FILE_X) variables. */
void dt_import_session_set_filename(struct dt_import_session_t *self, const char *filename);

/** \brief current film id for the import session */
int32_t dt_import_session_film_id(struct dt_import_session_t *self);

/** \brief get import session name */
const char *dt_import_session_name(struct dt_import_session_t *self);
/** \brief get import session filename.
    \param[in] current If TRUE the current filename will be returned without evaluating a new filename.
 */
const char *dt_import_session_filename(struct dt_import_session_t *self);
/** \brief get import session path
    \param[in] use_filename If TRUE the filename passed by dt_import_session_set_filename will be returned
    without evaluating a new filename.
*/
const char *dt_import_session_path(struct dt_import_session_t *self, gboolean current);

/*load path and file patter, assemble them together, then expand all $() without doing unnecessarry checks */
const char *dt_import_session_total(struct dt_import_session_t *self);

// clang-format off
// modelines: These editor modelines have been set for all relevant files by tools/update_modelines.py
// vim: shiftwidth=2 expandtab tabstop=2 cindent
// kate: tab-indents: off; indent-width 2; replace-tabs on; indent-mode cstyle; remove-trailing-spaces modified;
// clang-format on
