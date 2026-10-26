
undefined4 * FUN_0072e0d0(void)

{
  char cVar1;
  undefined4 *in_EAX;
  int iVar2;
  char *pcVar3;
  int *in_ECX;
  int *piVar4;
  undefined **local_8;
  
  if (in_EAX[5] != 0) {
    in_EAX[4] = in_ECX;
    in_EAX[0xf] = in_ECX[7];
    in_EAX[0x10] = 0;
    if (in_ECX[7] != 0) {
      *(undefined4 **)(in_ECX[7] + 0x40) = in_EAX;
      in_ECX[7] = (int)in_EAX;
      return in_EAX;
    }
    in_ECX[6] = (int)in_EAX;
    in_ECX[7] = (int)in_EAX;
    return in_EAX;
  }
  (**(code **)*in_EAX)(1);
  piVar4 = in_ECX;
  if (in_ECX != (int *)0x0) {
    while (iVar2 = (**(code **)(*piVar4 + 0x10))(), iVar2 == 0) {
      piVar4 = (int *)piVar4[4];
      if (piVar4 == (int *)0x0) {
        return (undefined4 *)0x0;
      }
    }
    iVar2 = (**(code **)(*piVar4 + 0x10))();
    if (iVar2 != 0) {
      do {
        iVar2 = (**(code **)(*in_ECX + 0x10))();
        if (iVar2 != 0) {
          iVar2 = (**(code **)(*in_ECX + 0x10))();
          goto LAB_0072e136;
        }
        in_ECX = (int *)in_ECX[4];
      } while (in_ECX != (int *)0x0);
      iVar2 = 0;
LAB_0072e136:
      if (*(char *)(iVar2 + 0x44) == '\0') {
        *(undefined1 *)(iVar2 + 0x44) = 1;
        *(undefined4 *)(iVar2 + 0x48) = 0x10;
        pcVar3 = PTR_s_Error_when_TiXmlDocument_added_t_00d63cc8;
        do {
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(PTR_s_Error_when_TiXmlDocument_added_t_00d63cc8,
                     (int)pcVar3 - (int)(PTR_s_Error_when_TiXmlDocument_added_t_00d63cc8 + 1));
        *(undefined4 *)(iVar2 + 0x70) = 0xffffffff;
        *(undefined4 *)(iVar2 + 0x6c) = 0xffffffff;
        local_8 = TiXmlErrorReporter::vftable;
        FUN_00731de0(&local_8,0,0,0);
      }
    }
  }
  return (undefined4 *)0x0;
}

