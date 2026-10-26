
undefined4 FUN_0072e1e0(void)

{
  int *piVar1;
  char cVar2;
  int *in_EAX;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int *in_ECX;
  int *piVar6;
  undefined **local_8;
  
  if (in_ECX[5] != 0) {
    iVar3 = (**(code **)(*in_ECX + 0x3c))();
    if (iVar3 == 0) {
      return 0;
    }
    uVar5 = FUN_0072e0d0();
    return uVar5;
  }
  piVar6 = in_EAX;
  if (in_EAX != (int *)0x0) {
    while (iVar3 = (**(code **)(*piVar6 + 0x10))(), iVar3 == 0) {
      piVar1 = piVar6 + 4;
      piVar6 = (int *)*piVar1;
      if ((int *)*piVar1 == (int *)0x0) {
        return 0;
      }
    }
    iVar3 = (**(code **)(*piVar6 + 0x10))();
    if (iVar3 != 0) {
      do {
        iVar3 = (**(code **)(*in_EAX + 0x10))();
        if (iVar3 != 0) {
          iVar3 = (**(code **)(*in_EAX + 0x10))();
          break;
        }
        in_EAX = (int *)in_EAX[4];
        iVar3 = 0;
      } while (in_EAX != (int *)0x0);
      if (*(char *)(iVar3 + 0x44) == '\0') {
        *(undefined1 *)(iVar3 + 0x44) = 1;
        *(undefined4 *)(iVar3 + 0x48) = 0x10;
        pcVar4 = PTR_s_Error_when_TiXmlDocument_added_t_00d63cc8;
        do {
          cVar2 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
        FUN_00402a70(PTR_s_Error_when_TiXmlDocument_added_t_00d63cc8,
                     (int)pcVar4 - (int)(PTR_s_Error_when_TiXmlDocument_added_t_00d63cc8 + 1));
        *(undefined4 *)(iVar3 + 0x70) = 0xffffffff;
        *(undefined4 *)(iVar3 + 0x6c) = 0xffffffff;
        local_8 = TiXmlErrorReporter::vftable;
        FUN_00731de0(&local_8,0,0,0);
      }
    }
  }
  return 0;
}

