// name    :  spammodule.c
// version :  0.0.1
// date    :  20241111
// author  :  
// desc    :  
//
#define PY_SSIZE_T_CLEAN
#include <Python.h>

int main(int argc, char *argv[]) {
        PyStatus status;
        PyConfig config;
        PyConfig_InitPythonConfig(&config);

        if (PyImport_AppendInittab("spam", PyInit_spam) == -1) {
            fprintf(stderr, "Error: could not extend modules table\n");
            exit(1);
        }

        status = PyConfig_SetBytesString(&config, &config.program_name, argv[0]);
        if (PyStatus_Exception(status)) {
            // Hey, I'm just copying code here! GOTO is not my idea!
            goto exception;
        } 

        status = Py_InitializeFromConfig(&config);
        if (PyStatus_Exception(status)) {
            goto exception;
        }
        PyConfig_Clear(&config);

        PyObject *pmodule = PyImport_ImportModule("spam");
        if (!pmodule) {
            PyErr_Print();
            fprintf(stderr, "Error: could not import module spam\n");
        }

        return 0;

    exception:
        PyConfig_Clear(&config);
        Py_ExitStatusException(status);
}


static PyObject *spam_system(PyObject *self, PyObject *args) {
    const char *command;
    int sys;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    return PyLong_FromLong(sts);
}

static PyObject *SpamError;
PyMODINIT_FUNC PyInit_spam(void) {
    PyObject *m;
    m = PyModule_Create(&spammodule);
    if (m == NULL)
        return NULL;
    SpamError = PyErr_NewException("spam.error", NULL, NULL);
    if (PyModule_AddObjectRef(m, "error", SpamError) < 0) {
        Py_CLEAR(SpamError);
        Py_DECREF(m);
        return null;
    }
    return m;
}

static PyObject *spam_system(PyObject *self, PyObject *args) {
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    if (sts < 0) {
        PyErr_SetString(SpamError, "System command failed");
        return NULL;
    }
    return PyLong_FromLong(sts);
}

static PyMethodDef SpamMethods[] {
    ...
    {"system", spam_system, METH_VARARGS, "Execute shell cmd."},
    ...
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef spammodule = {
    PyModuleDef_HEAD_INIT,
    "spam",
    spam_doc,
    -1,
    SpamMethods
};

PyMODINITFUNC PyInit_spam(void) {
    return PyModule_Create(&spammodule);
}


