/*
 * Defines.h
 *
 *  Created on: Mar 22, 2011
 *      Author: nimrod
 */

#ifndef DEFINES_H_
#define DEFINES_H_

#include <string>
using std::string;

namespace differential {

struct Defines {

static const string kLabelPrefix;
static const string kLabelEnd;
static const string kLabelStart;

static const string kTagPrefix;
static const string kTagParamDef;

static const string kInitPrefix;

static const string kGuardPrefix;
static const string kGuardType;
static const string kGuardTypedef;

static const string kGeneralTypedefs;

static const string kDiffPointPrefix;

static const string kRetGuard;
static const string kRetGuardType;
static const string kRetGuardTypedef;

static const string kRetVal;

static const string kAssertPrefix;

static const string kTempPrefix;

static const string kPatchedFilenamePrefix;
static const string kGuardedFilenamePrefix;
static const string kTaggedFilenamePrefix;
static const string kUnionedFilenamePrefix;
static const string kInlinedFilenamePrefix;
static const string kResultsFilenamePrefix;
static const string kTypedefsFilenamePrefix;
};

}


#endif /* DEFINES_H_ */
