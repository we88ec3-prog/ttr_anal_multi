
byte FUN_0072a690(int *param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint local_8;
  
  local_8 = 0xffff;
  if (param_1[3] - 5U < 0xffff) {
    local_8 = param_1[3] - 5U;
  }
  do {
    uVar2 = param_1[0x1d];
    if (uVar2 < 2) {
      FUN_0072a540();
      uVar2 = param_1[0x1d];
      if (uVar2 == 0) {
        if (param_2 == 0) {
          return 0;
        }
        if (param_1[0x17] < 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = param_1[0xe] + param_1[0x17];
        }
        FUN_0072d0f0(iVar3,param_2 == 4);
        param_1[0x17] = param_1[0x1b];
        FUN_007299d0();
        if (*(int *)(*param_1 + 0x10) != 0) {
          return (param_2 == 4) * '\x02' + 1;
        }
        return (param_2 != 4) - 1U & 2;
      }
    }
    piVar1 = param_1 + 0x1b;
    *piVar1 = *piVar1 + uVar2;
    iVar3 = param_1[0x17];
    param_1[0x1d] = 0;
    uVar2 = iVar3 + local_8;
    if ((*piVar1 == 0) || (uVar2 <= (uint)param_1[0x1b])) {
      param_1[0x1d] = param_1[0x1b] - uVar2;
      param_1[0x1b] = uVar2;
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = param_1[0xe] + iVar3;
      }
      FUN_0072d0f0(iVar3,0);
      iVar3 = *param_1;
      param_1[0x17] = param_1[0x1b];
      uVar2 = *(uint *)(*(int *)(iVar3 + 0x1c) + 0x14);
      if (*(uint *)(iVar3 + 0x10) < uVar2) {
        uVar2 = *(uint *)(iVar3 + 0x10);
      }
      if (uVar2 != 0) {
        FID_conflict__memcpy
                  (*(void **)(iVar3 + 0xc),*(void **)(*(int *)(iVar3 + 0x1c) + 0x10),uVar2);
        *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + uVar2;
        piVar1 = (int *)(*(int *)(iVar3 + 0x1c) + 0x10);
        *piVar1 = *piVar1 + uVar2;
        *(int *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + uVar2;
        *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) - uVar2;
        piVar1 = (int *)(*(int *)(iVar3 + 0x1c) + 0x14);
        *piVar1 = *piVar1 - uVar2;
        iVar3 = *(int *)(iVar3 + 0x1c);
        if (*(int *)(iVar3 + 0x14) == 0) {
          *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(iVar3 + 8);
        }
      }
      if (*(int *)(*param_1 + 0x10) == 0) {
        return 0;
      }
    }
    iVar3 = param_1[0x17];
    if (param_1[0xb] - 0x106U <= (uint)(param_1[0x1b] - iVar3)) {
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = param_1[0xe] + iVar3;
      }
      FUN_0072d0f0(iVar3,0);
      iVar3 = *param_1;
      param_1[0x17] = param_1[0x1b];
      uVar2 = *(uint *)(*(int *)(iVar3 + 0x1c) + 0x14);
      if (*(uint *)(iVar3 + 0x10) < uVar2) {
        uVar2 = *(uint *)(iVar3 + 0x10);
      }
      if (uVar2 != 0) {
        FID_conflict__memcpy
                  (*(void **)(iVar3 + 0xc),*(void **)(*(int *)(iVar3 + 0x1c) + 0x10),uVar2);
        *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + uVar2;
        piVar1 = (int *)(*(int *)(iVar3 + 0x1c) + 0x10);
        *piVar1 = *piVar1 + uVar2;
        *(int *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + uVar2;
        *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) - uVar2;
        piVar1 = (int *)(*(int *)(iVar3 + 0x1c) + 0x14);
        *piVar1 = *piVar1 - uVar2;
        iVar3 = *(int *)(iVar3 + 0x1c);
        if (*(int *)(iVar3 + 0x14) == 0) {
          *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(iVar3 + 8);
        }
      }
      if (*(int *)(*param_1 + 0x10) == 0) {
        return 0;
      }
    }
  } while( true );
}

