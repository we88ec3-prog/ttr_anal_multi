
void * FUN_006f7170(undefined4 param_1,void *param_2,undefined4 param_3,size_t param_4)

{
  void *pvVar1;
  
  if (param_4 == 0) {
    _free(param_2);
    return (void *)0x0;
  }
  pvVar1 = _realloc(param_2,param_4);
  return pvVar1;
}

