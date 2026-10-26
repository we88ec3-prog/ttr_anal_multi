
int FUN_008d69d0(undefined4 param_1)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  int *unaff_ESI;
  int *unaff_EDI;
  int local_8;
  
  local_8 = 0;
  (*(code *)**(undefined4 **)(in_EAX + 4))();
  unaff_ESI[0x12] = (int)unaff_EDI;
  unaff_ESI[0x14] = 0;
  unaff_ESI[0x13] = 0;
  *(undefined1 *)(unaff_ESI + 0x15) = 0;
  local_8 = FUN_008b97e0();
  if ((local_8 == 0) && (local_8 = FUN_008babe0(), local_8 == 0)) {
    piVar5 = (int *)unaff_EDI[8];
    uVar2 = 0x11;
    pcVar4 = "%!PS-TrueTypeFont";
    do {
      if (*piVar5 != *(int *)pcVar4) goto LAB_008d6a40;
      uVar2 = uVar2 - 4;
      pcVar4 = (char *)((int)pcVar4 + 4);
      piVar5 = piVar5 + 1;
    } while (3 < uVar2);
    if ((char)*(int *)pcVar4 != (char)*piVar5) {
LAB_008d6a40:
      local_8 = 2;
    }
    FUN_008baca0();
    if ((local_8 == 0) && (local_8 = FUN_008b97e0(), local_8 == 0)) {
      iVar1 = unaff_EDI[1];
      if (unaff_EDI[5] == 0) {
        unaff_ESI[0x13] = unaff_EDI[2] + *unaff_EDI;
        unaff_ESI[0x14] = iVar1;
        *(undefined1 *)(unaff_ESI + 0x15) = 1;
        local_8 = FUN_008b9820();
        if (local_8 == 0) {
LAB_008d6ae8:
          iVar1 = unaff_ESI[0x13];
          unaff_ESI[1] = iVar1;
          *unaff_ESI = iVar1;
          unaff_ESI[2] = unaff_ESI[0x14] + iVar1;
          return 0;
        }
      }
      else {
        iVar3 = FUN_008baee0(param_1,iVar1,&local_8);
        unaff_ESI[0x13] = iVar3;
        if ((local_8 == 0) && (local_8 = FUN_008bab70(), local_8 == 0)) {
          unaff_ESI[0x14] = iVar1;
          goto LAB_008d6ae8;
        }
      }
    }
  }
  if ((char)unaff_ESI[0x15] == '\0') {
    FUN_008b9f80(param_1,unaff_ESI[0x13]);
    unaff_ESI[0x13] = 0;
  }
  return local_8;
}

