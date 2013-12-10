/*
 * Defines.cpp
 *
 *  Created on: Mar 22, 2011
 *      Author: nimrod
 */
#include "Defines.h"

namespace differential {

const string Defines::kArrayIndexPostfix = "_idx";
const string Defines::kLabelPrefix = "L";
const string Defines::kLabelEnd = "End_";
const string Defines::kLabelStart = "Start_";
const string Defines::kTagPrefix = "'";
const string Defines::kTagPostfix = "'";
const string Defines::kInitPrefix = "I_";
const string Defines::kTagParamDef = "/*TP*/ ";
const string Defines::kGuardPrefix = "G";
const string Defines::kGuardType = "Guard";
const string Defines::kGuardTypedef = "typedef short Guard;\n";
const string Defines::kGeneralTypedefs = "typedef int _Bool;\n";
const string Defines::kRetGuardType = Defines::kGuardType;//"RetGuard";
const string Defines::kRetGuardTypedef = "";//"typedef short RetGuard;\n";
const string Defines::kCorrPointPrefix = "CP";
const string Defines::kRetGuard = "Ret";
const string Defines::kRetVal = "RetVal";
const string Defines::kAssertPrefix = "//assert";
const string Defines::kTempPrefix = "Temp_";
const string Defines::kPatchedFilenamePrefix = "patched.";
const string Defines::kGuardedFilenamePrefix = "guarded.";
const string Defines::kTaggedFilenamePrefix = "tagged.";
const string Defines::kUnionedFilenamePrefix = "union.";
const string Defines::kInlinedFilenamePrefix = "inlined.";
const string Defines::kResultsFilenamePrefix = "results.";
const string Defines::kTypedefsFilenamePrefix = "typedefs.";
}
