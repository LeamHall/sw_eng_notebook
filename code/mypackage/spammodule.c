#include <Python.h>

static PyObject* spam(PyObject* self, PyObject* args) {
    const char* name;

    if (!PyArg_ParseTuple(args, "s", &name)) {
        return NULL;
    }

    printf("Hello, %s, SPAM...SPAM...SPAM!\n", name);

    Py_RETURN_NONE;
}

static PyMethodDef SpamMethods[] = {
    {"hello", spam, METH_VARARGS, "Print a hello message."},
    {NULL, NULL, 0, NULL} /* Sentinel */
};

static struct PyModuleDef spam_module = {
    PyModuleDef_HEAD_INIT,
    "spam",         /* name of module */
    NULL,           /* module documentation, may be NULL */
    -1,             /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    SpamMethods
};

PyMODINIT_FUNC PyInit_spam(void) {
    return PyModule_Create(&spam_module);
}
