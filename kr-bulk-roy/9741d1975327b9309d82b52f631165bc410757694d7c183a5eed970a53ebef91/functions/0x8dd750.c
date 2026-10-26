
int FUN_008dd750(int param_1,byte *param_2)

{
  uint uVar1;
  int iVar2;
  byte *in_EDX;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int local_14;
  int local_c;
  byte *local_8;
  
  local_c = 0;
  *(int *)(param_1 + 0x194) = param_1 + 0x10;
  *(byte **)(param_1 + 4) = in_EDX;
  *(byte **)(param_1 + 8) = param_2;
  *(byte **)(param_1 + 0xc) = in_EDX;
  local_8 = in_EDX;
  if (param_2 <= in_EDX) {
    return 0;
  }
  while ((uVar1 = (uint)*local_8, 0x1a < uVar1 && (uVar1 != 0x1f))) {
    if (0x17f < (int)((int)*(undefined4 **)(param_1 + 0x194) + (-0x10 - param_1) & 0xfffffffcU)) {
      return 6;
    }
    **(undefined4 **)(param_1 + 0x194) = local_8;
    *(int *)(param_1 + 0x194) = *(int *)(param_1 + 0x194) + 4;
    if (uVar1 == 0x1e) {
      do {
        local_8 = local_8 + 1;
        if (param_2 <= local_8) {
          return local_c;
        }
      } while (((*local_8 & 0xf0) != 0xf0) && ((*local_8 & 0xf) != 0xf));
    }
    else if (uVar1 == 0x1c) {
      local_8 = local_8 + 2;
    }
    else if (uVar1 == 0x1d) {
      local_8 = local_8 + 4;
    }
    else if (0xf6 < uVar1) {
      local_8 = local_8 + 1;
    }
LAB_008dd939:
    local_8 = local_8 + 1;
    if (param_2 <= local_8) {
      return local_c;
    }
  }
  uVar3 = (int)*(undefined4 **)(param_1 + 0x194) + (-0x10 - param_1) >> 2;
  **(undefined4 **)(param_1 + 0x194) = local_8;
  if (uVar1 == 0xc) {
    local_8 = local_8 + 1;
    if (param_2 <= local_8) {
      return 6;
    }
    uVar1 = *local_8 | 0x100;
  }
  piVar5 = (int *)&DAT_00be9380;
  while (piVar5[1] != (uVar1 | *(uint *)(param_1 + 0x198))) {
    piVar5 = piVar5 + 7;
    if (*piVar5 == 0) goto LAB_008dd92d;
  }
  piVar4 = (int *)(piVar5[2] + *(int *)(param_1 + 0x19c));
  if ((*piVar5 != 6) && (uVar3 == 0)) {
    return 6;
  }
  switch(*piVar5) {
  case 1:
  case 4:
  case 5:
    iVar2 = FUN_008dd460();
    break;
  case 2:
    iVar2 = FUN_008dd4e0();
    break;
  case 3:
    iVar2 = thunk_FUN_008dd490();
    break;
  case 6:
    if ((uint)piVar5[5] < uVar3) {
      uVar3 = piVar5[5];
    }
    *(char *)(piVar5[6] + *(int *)(param_1 + 0x19c)) = (char)uVar3;
    local_14 = 0;
    for (; uVar3 != 0; uVar3 = uVar3 - 1) {
      iVar2 = FUN_008dd460();
      local_14 = local_14 + iVar2;
      if ((char)piVar5[3] == '\x01') {
        *(char *)piVar4 = (char)local_14;
      }
      else if ((char)piVar5[3] == '\x02') {
        *(short *)piVar4 = (short)local_14;
      }
      else {
        *piVar4 = local_14;
      }
      piVar4 = (int *)((int)piVar4 + (uint)*(byte *)(piVar5 + 3));
    }
LAB_008dd92d:
    *(int *)(param_1 + 0x194) = param_1 + 0x10;
    goto LAB_008dd939;
  default:
    local_c = (*(code *)piVar5[4])(param_1);
    if (local_c != 0) {
      return local_c;
    }
    goto LAB_008dd92d;
  }
  if ((char)piVar5[3] == '\x01') {
    *(char *)piVar4 = (char)iVar2;
  }
  else if ((char)piVar5[3] == '\x02') {
    *(short *)piVar4 = (short)iVar2;
  }
  else {
    *piVar4 = iVar2;
  }
  goto LAB_008dd92d;
}

