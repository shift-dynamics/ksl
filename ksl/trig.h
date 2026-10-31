/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Additional math utilities for KSL library
@date 2018
@copyright Kristopher Wehage 2018

@remark
THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
SUCH DAMAGE.
*/
#ifndef _KSL_TRIG_H_
#define _KSL_TRIG_H_

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
@brief compute double precision direction cosines from an angle specified in
radians

@param thetai [in] input angle
@param dc [out] direction cosines, with sine stored in dc[0] and cosine is
stored in dc[1]
*/
void ksl_dc(const double thetai, double dc[2]);

/*!
@brief compute single precision direction cosines from an angle specified in
radians

@param thetai [in] input angle
@param dc [out] direction cosines, with sine stored in dc[0] and cosine is
stored in dc[1]
*/
void ksl_dcf(const float thetai, float dc[2]);

double ksl_normalizeDegrees(double angle);

float ksl_normalizeDegreesf(float angle);

double ksl_normalizeRadians(double angle);

float ksl_normalizeRadiansf(float angle);

double catan2pi(const double y, const double x, double theta);

float catan2pif(const float y, const float x, float theta);

double catan1pi(const double y, const double x, double theta);

float catan1pif(const float y, const float x, float theta);

#ifdef __cplusplus
}
#endif

#endif
