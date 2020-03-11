/**************************************************************************
 *
 *         Copyright (c) 2014-2018 by iCatch Technology, Inc.
 *
 *  This software is copyrighted by and is the property of Sunplus
 *  Technology, Inc. All rights are reserved by Sunplus Technology, Inc.
 *  This software may only be used in accordance with the
 *  corresponding license agreement. Any unauthorized use, duplication,
 *  distribution, or disclosure of this software is expressly forbidden.
 *
 *  This Copyright notice MUST not be removed or modified without prior
 *  written consent of iCatch Technology, Inc.
 *
 *  iCatch Technology, Inc. reserves the right to modify this
 *  software without notice.
 *
 *  iCatch Technology, Inc.
 *  19-1, Innovation First Road, Science-Based Industrial Park,
 *  Hsin-Chu, Taiwan, R.O.C.
 *
 *  Author: peng.tan
 *  Email:  peng.tan@sunmedia.com.cn
 *
 **************************************************************************/

#ifndef __ICATCH_I_GL_FUNCTIONS_H__
#define __ICATCH_I_GL_FUNCTIONS_H__

/* -----------------------------------------------------------------------------
 * Header files, namespace references.
 */
#include <stdint.h>

typedef uint8_t     IGLubyte;
typedef float       IGLclampf;
typedef float       IGLfloat;
typedef int16_t     IGLshort;
typedef uint16_t    IGLushort;
typedef void        IGLvoid;
typedef uint32_t    IGLenum;
typedef uint32_t    IGLuint;
typedef char        IGLchar;
typedef uint32_t    IGLbitfield;
typedef int32_t     IGLint;
typedef uint8_t     IGLboolean;
typedef int32_t     IGLsizei;
typedef int64_t     IGLsizeiptr;

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

/**
 * The interface to render panoramic image.
 */
class ICatchIGLFunctions
{
public:
    virtual ~ICatchIGLFunctions() { };

public:
    // GLES2 + OpenGL1 common subset
    virtual void _glBindTexture(IGLenum target, IGLuint texture) = 0;
    virtual void _glBlendFunc(IGLenum sfactor, IGLenum dfactor) = 0;
    virtual void _glClear(IGLbitfield mask) = 0;
    virtual void _glClearColor(IGLclampf red, IGLclampf green, IGLclampf blue, IGLclampf alpha) = 0;
    virtual void _glClearStencil(IGLint s) = 0;
    virtual void _glColorMask(IGLboolean red, IGLboolean green, IGLboolean blue, IGLboolean alpha) = 0;
    virtual void _glCopyTexImage2D(IGLenum target, IGLint level, IGLenum internalformat, IGLint x, IGLint y, IGLsizei width, IGLsizei height, IGLint border) = 0;
    virtual void _glCopyTexSubImage2D(IGLenum target, IGLint level, IGLint xoffset, IGLint yoffset, IGLint x, IGLint y, IGLsizei width, IGLsizei height) = 0;
    virtual void _glCullFace(IGLenum mode) = 0;
    virtual void _glDeleteTextures(IGLsizei n, const IGLuint* textures) = 0;
    virtual void _glDepthFunc(IGLenum func) = 0;
    virtual void _glDepthMask(IGLboolean flag) = 0;
    virtual void _glDisable(IGLenum cap) = 0;
    virtual void _glDrawArrays(IGLenum mode, IGLint first, IGLsizei count) = 0;
    virtual void _glDrawElements(IGLenum mode, IGLsizei count, IGLenum type, const IGLvoid* indices) = 0;
    virtual void _glEnable(IGLenum cap) = 0;
    virtual void _glFinish() = 0;
    virtual void _glFlush() = 0;
    virtual void _glFrontFace(IGLenum mode) = 0;
    virtual void _glGenTextures(IGLsizei n, IGLuint* textures) = 0;
    virtual void _glGetBooleanv(IGLenum pname, IGLboolean* params) = 0;
    virtual IGLenum _glGetError() = 0;
    virtual void _glGetFloatv(IGLenum pname, IGLfloat* params) = 0;
    virtual void _glGetIntegerv(IGLenum pname, IGLint* params) = 0;
    virtual const IGLubyte *_glGetString(IGLenum name) = 0;
    virtual void _glGetTexParameterfv(IGLenum target, IGLenum pname, IGLfloat* params) = 0;
    virtual void _glGetTexParameteriv(IGLenum target, IGLenum pname, IGLint* params) = 0;
    virtual void _glHint(IGLenum target, IGLenum mode) = 0;
    virtual IGLboolean _glIsEnabled(IGLenum cap) = 0;
    virtual IGLboolean _glIsTexture(IGLuint texture) = 0;
    virtual void _glLineWidth(IGLfloat width) = 0;
    virtual void _glPixelStorei(IGLenum pname, IGLint param) = 0;
    virtual void _glPolygonOffset(IGLfloat factor, IGLfloat units) = 0;
    virtual void _glReadPixels(IGLint x, IGLint y, IGLsizei width, IGLsizei height, IGLenum format, IGLenum type, IGLvoid* pixels) = 0;
    virtual void _glScissor(IGLint x, IGLint y, IGLsizei width, IGLsizei height) = 0;
    virtual void _glStencilFunc(IGLenum func, IGLint ref, IGLuint mask) = 0;
    virtual void _glStencilMask(IGLuint mask) = 0;
    virtual void _glStencilOp(IGLenum fail, IGLenum zfail, IGLenum zpass) = 0;
    virtual void _glTexImage2D(IGLenum target, IGLint level, IGLint internalformat, IGLsizei width, IGLsizei height, IGLint border, IGLenum format, IGLenum type, const IGLvoid* pixels) = 0;
    virtual void _glTexParameterf(IGLenum target, IGLenum pname, IGLfloat param) = 0;
    virtual void _glTexParameterfv(IGLenum target, IGLenum pname, const IGLfloat* params) = 0;
    virtual void _glTexParameteri(IGLenum target, IGLenum pname, IGLint param) = 0;
    virtual void _glTexParameteriv(IGLenum target, IGLenum pname, const IGLint* params) = 0;
    virtual void _glTexSubImage2D(IGLenum target, IGLint level, IGLint xoffset, IGLint yoffset, IGLsizei width, IGLsizei height, IGLenum format, IGLenum type, const IGLvoid* pixels) = 0;
    virtual void _glViewport(IGLint x, IGLint y, IGLsizei width, IGLsizei height) = 0;

    // GL(ES)2
    virtual void _glActiveTexture(IGLenum texture) = 0;
    virtual void _glAttachShader(IGLuint program, IGLuint shader) = 0;
    virtual void _glBindAttribLocation(IGLuint program, IGLuint index, const char* name) = 0;
    virtual void _glBindBuffer(IGLenum target, IGLuint buffer) = 0;
    virtual void _glBindFramebuffer(IGLenum target, IGLuint framebuffer) = 0;
    virtual void _glBindRenderbuffer(IGLenum target, IGLuint renderbuffer) = 0;
    virtual void _glBlendColor(IGLclampf red, IGLclampf green, IGLclampf blue, IGLclampf alpha) = 0;
    virtual void _glBlendEquation(IGLenum mode) = 0;
    virtual void _glBlendEquationSeparate(IGLenum modeRGB, IGLenum modeAlpha) = 0;
    virtual void _glBlendFuncSeparate(IGLenum srcRGB, IGLenum dstRGB, IGLenum srcAlpha, IGLenum dstAlpha) = 0;
    virtual void _glBufferData(IGLenum target, IGLsizeiptr size, const void* data, IGLenum usage) = 0;
    virtual void _glBufferSubData(IGLenum target, IGLsizeiptr offset, IGLsizeiptr size, const void* data) = 0;
    virtual IGLenum _glCheckFramebufferStatus(IGLenum target) = 0;
    virtual void _glClearDepthf(IGLclampf depth) = 0;
    virtual void _glCompileShader(IGLuint shader) = 0;
    virtual void _glCompressedTexImage2D(IGLenum target, IGLint level, IGLenum internalformat, IGLsizei width, IGLsizei height, IGLint border, IGLsizei imageSize, const void* data) = 0;
    virtual void _glCompressedTexSubImage2D(IGLenum target, IGLint level, IGLint xoffset, IGLint yoffset, IGLsizei width, IGLsizei height, IGLenum format, IGLsizei imageSize, const void* data) = 0;
    virtual IGLuint _glCreateProgram() = 0;
    virtual IGLuint _glCreateShader(IGLenum type) = 0;
    virtual void _glDeleteBuffers(IGLsizei n, const IGLuint* buffers) = 0;
    virtual void _glDeleteFramebuffers(IGLsizei n, const IGLuint* framebuffers) = 0;
    virtual void _glDeleteProgram(IGLuint program) = 0;
    virtual void _glDeleteRenderbuffers(IGLsizei n, const IGLuint* renderbuffers) = 0;
    virtual void _glDeleteShader(IGLuint shader) = 0;
    virtual void _glDepthRangef(IGLclampf zNear, IGLclampf zFar) = 0;
    virtual void _glDetachShader(IGLuint program, IGLuint shader) = 0;
    virtual void _glDisableVertexAttribArray(IGLuint index) = 0;
    virtual void _glEnableVertexAttribArray(IGLuint index) = 0;
    virtual void _glFramebufferRenderbuffer(IGLenum target, IGLenum attachment, IGLenum renderbuffertarget, IGLuint renderbuffer) = 0;
    virtual void _glFramebufferTexture2D(IGLenum target, IGLenum attachment, IGLenum textarget, IGLuint texture, IGLint level) = 0;
    virtual void _glGenBuffers(IGLsizei n, IGLuint* buffers) = 0;
    virtual void _glGenerateMipmap(IGLenum target) = 0;
    virtual void _glGenFramebuffers(IGLsizei n, IGLuint* framebuffers) = 0;
    virtual void _glGenRenderbuffers(IGLsizei n, IGLuint* renderbuffers) = 0;
    virtual void _glGetActiveAttrib(IGLuint program, IGLuint index, IGLsizei bufsize, IGLsizei* length, IGLint* size, IGLenum* type, char* name) = 0;
    virtual void _glGetActiveUniform(IGLuint program, IGLuint index, IGLsizei bufsize, IGLsizei* length, IGLint* size, IGLenum* type, char* name) = 0;
    virtual void _glGetAttachedShaders(IGLuint program, IGLsizei maxcount, IGLsizei* count, IGLuint* shaders) = 0;
    virtual IGLint _glGetAttribLocation(IGLuint program, const char* name) = 0;
    virtual void _glGetBufferParameteriv(IGLenum target, IGLenum pname, IGLint* params) = 0;
    virtual void _glGetFramebufferAttachmentParameteriv(IGLenum target, IGLenum attachment, IGLenum pname, IGLint* params) = 0;
    virtual void _glGetProgramiv(IGLuint program, IGLenum pname, IGLint* params) = 0;
    virtual void _glGetProgramInfoLog(IGLuint program, IGLsizei bufsize, IGLsizei* length, char* infolog) = 0;
    virtual void _glGetRenderbufferParameteriv(IGLenum target, IGLenum pname, IGLint* params) = 0;
    virtual void _glGetShaderiv(IGLuint shader, IGLenum pname, IGLint* params) = 0;
    virtual void _glGetShaderInfoLog(IGLuint shader, IGLsizei bufsize, IGLsizei* length, char* infolog) = 0;
    virtual void _glGetShaderPrecisionFormat(IGLenum shadertype, IGLenum precisiontype, IGLint* range, IGLint* precision) = 0;
    virtual void _glGetShaderSource(IGLuint shader, IGLsizei bufsize, IGLsizei* length, char* source) = 0;
    virtual void _glGetUniformfv(IGLuint program, IGLint location, IGLfloat* params) = 0;
    virtual void _glGetUniformiv(IGLuint program, IGLint location, IGLint* params) = 0;
    virtual IGLint _glGetUniformLocation(IGLuint program, const char* name) = 0;
    virtual void _glGetVertexAttribfv(IGLuint index, IGLenum pname, IGLfloat* params) = 0;
    virtual void _glGetVertexAttribiv(IGLuint index, IGLenum pname, IGLint* params) = 0;
    virtual void _glGetVertexAttribPointerv(IGLuint index, IGLenum pname, void** pointer) = 0;
    virtual IGLboolean _glIsBuffer(IGLuint buffer) = 0;
    virtual IGLboolean _glIsFramebuffer(IGLuint framebuffer) = 0;
    virtual IGLboolean _glIsProgram(IGLuint program) = 0;
    virtual IGLboolean _glIsRenderbuffer(IGLuint renderbuffer) = 0;
    virtual IGLboolean _glIsShader(IGLuint shader) = 0;
    virtual void _glLinkProgram(IGLuint program) = 0;
    virtual void _glReleaseShaderCompiler() = 0;
    virtual void _glRenderbufferStorage(IGLenum target, IGLenum internalformat, IGLsizei width, IGLsizei height) = 0;
    virtual void _glSampleCoverage(IGLclampf value, IGLboolean invert) = 0;
    virtual void _glShaderBinary(IGLint n, const IGLuint* shaders, IGLenum binaryformat, const void* binary, IGLint length) = 0;
    virtual void _glShaderSource(IGLuint shader, IGLsizei count, const char** string, const IGLint* length) = 0;
    virtual void _glStencilFuncSeparate(IGLenum face, IGLenum func, IGLint ref, IGLuint mask) = 0;
    virtual void _glStencilMaskSeparate(IGLenum face, IGLuint mask) = 0;
    virtual void _glStencilOpSeparate(IGLenum face, IGLenum fail, IGLenum zfail, IGLenum zpass) = 0;
    virtual void _glUniform1f(IGLint location, IGLfloat x) = 0;
    virtual void _glUniform1fv(IGLint location, IGLsizei count, const IGLfloat* v) = 0;
    virtual void _glUniform1i(IGLint location, IGLint x) = 0;
    virtual void _glUniform1iv(IGLint location, IGLsizei count, const IGLint* v) = 0;
    virtual void _glUniform2f(IGLint location, IGLfloat x, IGLfloat y) = 0;
    virtual void _glUniform2fv(IGLint location, IGLsizei count, const IGLfloat* v) = 0;
    virtual void _glUniform2i(IGLint location, IGLint x, IGLint y) = 0;
    virtual void _glUniform2iv(IGLint location, IGLsizei count, const IGLint* v) = 0;
    virtual void _glUniform3f(IGLint location, IGLfloat x, IGLfloat y, IGLfloat z) = 0;
    virtual void _glUniform3fv(IGLint location, IGLsizei count, const IGLfloat* v) = 0;
    virtual void _glUniform3i(IGLint location, IGLint x, IGLint y, IGLint z) = 0;
    virtual void _glUniform3iv(IGLint location, IGLsizei count, const IGLint* v) = 0;
    virtual void _glUniform4f(IGLint location, IGLfloat x, IGLfloat y, IGLfloat z, IGLfloat w) = 0;
    virtual void _glUniform4fv(IGLint location, IGLsizei count, const IGLfloat* v) = 0;
    virtual void _glUniform4i(IGLint location, IGLint x, IGLint y, IGLint z, IGLint w) = 0;
    virtual void _glUniform4iv(IGLint location, IGLsizei count, const IGLint* v) = 0;
    virtual void _glUniformMatrix2fv(IGLint location, IGLsizei count, IGLboolean transpose, const IGLfloat* value) = 0;
    virtual void _glUniformMatrix3fv(IGLint location, IGLsizei count, IGLboolean transpose, const IGLfloat* value) = 0;
    virtual void _glUniformMatrix4fv(IGLint location, IGLsizei count, IGLboolean transpose, const IGLfloat* value) = 0;
    virtual void _glUseProgram(IGLuint program) = 0;
    virtual void _glValidateProgram(IGLuint program) = 0;
    virtual void _glVertexAttrib1f(IGLuint indx, IGLfloat x) = 0;
    virtual void _glVertexAttrib1fv(IGLuint indx, const IGLfloat* values) = 0;
    virtual void _glVertexAttrib2f(IGLuint indx, IGLfloat x, IGLfloat y) = 0;
    virtual void _glVertexAttrib2fv(IGLuint indx, const IGLfloat* values) = 0;
    virtual void _glVertexAttrib3f(IGLuint indx, IGLfloat x, IGLfloat y, IGLfloat z) = 0;
    virtual void _glVertexAttrib3fv(IGLuint indx, const IGLfloat* values) = 0;
    virtual void _glVertexAttrib4f(IGLuint indx, IGLfloat x, IGLfloat y, IGLfloat z, IGLfloat w) = 0;
    virtual void _glVertexAttrib4fv(IGLuint indx, const IGLfloat* values) = 0;
    virtual void _glVertexAttribPointer(IGLuint indx, IGLint size, IGLenum type, IGLboolean normalized, IGLsizei stride, const void* ptr) = 0;
};

}}}

#endif

