
void FUN_004d7c70(int param_1)

{
  int iVar1;
  int in_EAX;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *local_14;
  uint local_c;
  
  iVar1 = param_1 + in_EAX * 0x18;
  if (*(int *)(param_1 + 0x3c + in_EAX * 0x18) != 0) {
    piVar2 = (int *)FUN_00542210();
    if ((int *)*piVar2 == (int *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)*piVar2;
    }
    uVar3 = (uint)piVar2[2] >> 2;
    if (*(uint *)(iVar5 + 8) <= uVar3) {
      uVar3 = uVar3 - *(uint *)(iVar5 + 8);
    }
    iVar5 = *(int *)(*(int *)(*(int *)(iVar5 + 4) + uVar3 * 4) + (piVar2[2] & 3U) * 4);
    FUN_00542210();
    iVar4 = FUN_004d8460();
    if (local_c != *(uint *)(iVar4 + 8)) {
      do {
        if (local_14 == (int *)0x0) {
          iVar4 = 0;
        }
        else {
          iVar4 = *local_14;
        }
        uVar3 = local_c >> 1;
        if (*(uint *)(iVar4 + 8) <= uVar3) {
          uVar3 = uVar3 - *(uint *)(iVar4 + 8);
        }
        if (*(int *)(*(int *)(*(int *)(iVar4 + 4) + uVar3 * 4) + 4 + (local_c & 1) * 8) == iVar5) {
          if (iVar5 != 0) {
            FUN_004d7da0();
          }
          FUN_004d7ef0(param_1 + 0x14);
          break;
        }
        local_c = local_c + 1;
        iVar4 = FUN_004d8460();
      } while (local_c != *(uint *)(iVar4 + 8));
    }
    if (*(int *)(iVar1 + 0x3c) != 0) {
      *(int *)(iVar1 + 0x38) = *(int *)(iVar1 + 0x38) + 1;
      if ((uint)(*(int *)(iVar1 + 0x34) * 4) <= *(uint *)(iVar1 + 0x38)) {
        *(undefined4 *)(iVar1 + 0x38) = 0;
      }
      iVar5 = *(int *)(iVar1 + 0x3c) + -1;
      *(int *)(iVar1 + 0x3c) = iVar5;
      if (iVar5 == 0) {
        *(undefined4 *)(iVar1 + 0x38) = 0;
      }
    }
  }
  return;
}

