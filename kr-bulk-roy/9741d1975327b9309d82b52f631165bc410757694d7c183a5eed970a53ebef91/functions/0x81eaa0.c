
undefined4 FUN_0081eaa0(int param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  ushort *in_EAX;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint local_c;
  ushort *local_8;
  
  if (in_EAX == (ushort *)0x0) {
    return 0;
  }
  uVar1 = *in_EAX;
  local_8 = in_EAX;
  do {
    if (uVar1 == 0) {
      return 1;
    }
    uVar5 = (uint)*local_8;
    if (*local_8 < 0x80) {
      if ((((9 < uVar5 - 0x30) && (0x19 < uVar5 - 0x41)) && (0x19 < uVar5 - 0x61)) &&
         ((((param_2 & 0x20) == 0 || (uVar5 != 0x20)) &&
          (((param_2 & 0x100) == 0 || ((uVar5 != 0xd && (uVar5 != 10)))))))) {
        if ((param_2 & 0x80) == 0) {
          return 0;
        }
        if (0x5d < uVar5 - 0x21) {
          return 0;
        }
      }
    }
    else {
      iVar3 = (**(code **)(**(int **)(param_1 + 0x40) + 8))(uVar5);
      if ((((param_2 & 0x40) == 0) ||
          (iVar2 = *(int *)(param_1 + 0x40), local_c = uVar5, piVar4 = (int *)FUN_0081ed70(&local_c)
          , *piVar4 == *(int *)(iVar2 + 8))) && (iVar3 == 0)) {
        return 0;
      }
    }
    local_8 = local_8 + 1;
    uVar1 = *local_8;
  } while( true );
}

