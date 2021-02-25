// Copyright (C) 2019 - IIT Bombay - FOSSEE
//
// This file must be used under the terms of the CeCILL.
// This source file is licensed as described in the file COPYING, which
// you should have received as part of this distribution.  The terms
// are also available at
// http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt
// Author: Rupak Rokade
// Organization: FOSSEE, IIT Bombay
// Email: toolbox@scilab.in
extern "C"
{
    #include <Scierror.h>
    #include <api_scilab.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include "localization.h"
    #include "trans.h"

    static const char fname[] = "transpose";
    int sci_transpose(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt* opt, int nout, scilabVar* out)
    {
        int row = 0;
        int col = 0;
        int size = 0;
        double* inputMatrix = NULL;
        double* outputMatrix = NULL;
        
        // Input Error handling
        if (nin != 1)
        {
            Scierror(77, _("%s: Wrong number of input argument(s): %d expected.\n"), fname, 1);
            return 1;
        }

        if (nout != 1)
        {
            Scierror(77, _("%s: Wrong number of output argument(s): %d expected.\n"), fname, 1);
            return 1;
        }

        if (scilab_isMatrix2d(env, in[0]) == 0)
        {
            Scierror(52, _("%s: Wrong type for argument(s): %d Real matrix expected.\n"), fname, 1);
            return 1;
        }

        // get dimension of matrix
        size = scilab_getDim2d(env, in[0], &row, &col);

        // get input matrix
        scilab_getDoubleArray(env, in[0], &inputMatrix);

        // create temp matrix to store tranpose
        double* tempMatrix = (double*) malloc(col * row * sizeof(double));
        transpose(inputMatrix, row, col, tempMatrix);

        // create output matrix
        out[0] = scilab_createDoubleMatrix2d(env, col, row, 0);
        scilab_getDoubleArray(env, out[0], &outputMatrix);

        // transfer transpose to output
        for (int i = 0; i < size; i++){
            outputMatrix[i] = tempMatrix[i];
        }

        return 0;
    }
}
