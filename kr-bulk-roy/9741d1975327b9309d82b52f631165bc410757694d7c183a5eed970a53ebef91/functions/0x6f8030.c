
undefined4 FUN_006f8030(undefined4 param_1,char *param_2,int param_3,int param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_ESI;
  undefined4 local_8;
  
  local_8 = 1;
  if (param_3 == 0) {
    *(undefined1 **)(unaff_ESI + 8) = &DAT_00bf2375;
    *(undefined1 **)(unaff_ESI + 4) = &DAT_00bf2375;
    *(undefined4 *)(unaff_ESI + 0x14) = 0xffffffff;
    *(undefined4 *)(unaff_ESI + 0x1c) = 0xffffffff;
    *(undefined4 *)(unaff_ESI + 0x20) = 0xffffffff;
    *(undefined **)(unaff_ESI + 0xc) = &DAT_00c428dc;
    *(char **)(unaff_ESI + 0x10) = "=(tail call)";
    FUN_006f7c50(unaff_ESI + 0x24);
    *(undefined4 *)(unaff_ESI + 0x18) = 0;
    return 1;
  }
  cVar1 = *param_2;
  while (cVar1 != '\0') {
    switch(cVar1) {
    case 'L':
    case 'f':
      break;
    default:
      local_8 = 0;
      break;
    case 'S':
      FUN_006f7ec0();
      break;
    case 'l':
      if (param_4 == 0) {
        *(undefined4 *)(unaff_ESI + 0x14) = 0xffffffff;
      }
      else {
        uVar2 = FUN_006f7d80();
        *(undefined4 *)(unaff_ESI + 0x14) = uVar2;
      }
      break;
    case 'n':
      if (param_4 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_006f88d0(unaff_ESI + 4);
      }
      *(int *)(unaff_ESI + 8) = iVar3;
      if (iVar3 == 0) {
        *(undefined1 **)(unaff_ESI + 8) = &DAT_00bf2375;
        *(undefined4 *)(unaff_ESI + 4) = 0;
      }
      break;
    case 'u':
      *(uint *)(unaff_ESI + 0x18) = (uint)*(byte *)(param_3 + 7);
    }
    param_2 = param_2 + 1;
    cVar1 = *param_2;
  }
  return local_8;
}

