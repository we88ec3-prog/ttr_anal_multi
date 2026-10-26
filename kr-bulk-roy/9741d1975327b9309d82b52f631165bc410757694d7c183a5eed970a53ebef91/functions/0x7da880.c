
int FUN_007da880(void *param_1,size_t param_2)

{
  uint uVar1;
  uint in_EAX;
  undefined4 *puVar2;
  void *pvVar3;
  undefined4 *in_ECX;
  undefined4 *puVar4;
  char *pcVar5;
  
  uVar1 = in_ECX[4];
  if (in_EAX < uVar1) {
    puVar4 = in_ECX;
    if (0xf < (uint)in_ECX[5]) {
      puVar4 = (undefined4 *)*in_ECX;
    }
    puVar2 = in_ECX;
    if (0xf < (uint)in_ECX[5]) {
      puVar2 = (undefined4 *)*in_ECX;
    }
    for (pcVar5 = (char *)(in_EAX + (int)puVar2); pcVar5 < (char *)(uVar1 + (int)puVar4);
        pcVar5 = pcVar5 + 1) {
      pvVar3 = _memchr(param_1,(int)*pcVar5,param_2);
      if (pvVar3 == (void *)0x0) {
        if (0xf < (uint)in_ECX[5]) {
          in_ECX = (undefined4 *)*in_ECX;
        }
        return (int)pcVar5 - (int)in_ECX;
      }
    }
  }
  return -1;
}

