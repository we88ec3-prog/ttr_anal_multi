
undefined4 *
FUN_006efac0(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            void *param_5,size_t param_6,undefined4 param_7)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined4 *puVar3;
  size_t sVar4;
  undefined1 local_18 [8];
  undefined1 local_10 [12];
  
  while( true ) {
    pvVar2 = _memchr(param_5,0,param_6);
    sVar4 = param_6;
    if (pvVar2 != (void *)0x0) {
      sVar4 = (int)pvVar2 - (int)param_5;
    }
    puVar3 = (undefined4 *)FUN_006efa50(param_1,local_18,param_3,param_4,param_5,sVar4);
    param_3 = *puVar3;
    param_4 = puVar3[1];
    if (param_6 - sVar4 == 0) break;
    if ((char)param_7 != '\0') {
      puVar3 = (undefined4 *)FUN_006ef840(param_1,local_10,*puVar3,puVar3[1],param_7,1);
      param_3 = *puVar3;
      param_4 = puVar3[1];
    }
    param_5 = (void *)((int)param_5 + sVar4 + 1);
    param_6 = (param_6 - sVar4) - 1;
  }
  uVar1 = *puVar3;
  param_2[1] = puVar3[1];
  *param_2 = uVar1;
  return param_2;
}

