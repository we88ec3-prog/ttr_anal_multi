
int FUN_007da800(undefined4 *param_1,void *param_2,size_t param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  void *pvVar3;
  uint in_EDX;
  char *pcVar4;
  undefined4 *puVar5;
  
  if ((param_3 != 0) && (uVar1 = param_1[4], in_EDX < uVar1)) {
    puVar2 = param_1;
    if (0xf < (uint)param_1[5]) {
      puVar2 = (undefined4 *)*param_1;
    }
    puVar5 = param_1;
    if (0xf < (uint)param_1[5]) {
      puVar5 = (undefined4 *)*param_1;
    }
    for (pcVar4 = (char *)((int)puVar5 + in_EDX); pcVar4 < (char *)(uVar1 + (int)puVar2);
        pcVar4 = pcVar4 + 1) {
      pvVar3 = _memchr(param_2,(int)*pcVar4,param_3);
      if (pvVar3 != (void *)0x0) {
        if (0xf < (uint)param_1[5]) {
          param_1 = (undefined4 *)*param_1;
        }
        return (int)pcVar4 - (int)param_1;
      }
    }
  }
  return -1;
}

