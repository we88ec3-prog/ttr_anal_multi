
void FUN_006ec700(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_EDI;
  int local_10;
  int local_c;
  
  local_10 = 0;
  if (0 < (int)unaff_EDI[6]) {
    do {
      uVar1 = *(undefined4 *)(unaff_EDI[5] + local_10 * 4);
      local_c = 0;
      if (0 < (int)unaff_EDI[9]) {
        do {
          uVar2 = *(undefined4 *)(unaff_EDI[8] + local_c * 4);
          iVar4 = (**(code **)(*(int *)*param_1 + 0x2c))
                            ((int *)*param_1,*unaff_EDI,unaff_EDI[1],uVar1,unaff_EDI[4],uVar2,0);
          if (iVar4 < 0) {
            iVar4 = FUN_006ed240();
            if (-1 < iVar4) {
              iVar4 = unaff_EDI[0x12];
              iVar3 = unaff_EDI[0x11];
              *(undefined4 *)(iVar3 + iVar4 * 8) = uVar1;
              *(undefined4 *)(iVar3 + 4 + iVar4 * 8) = uVar2;
              unaff_EDI[0x12] = unaff_EDI[0x12] + 1;
            }
          }
          local_c = local_c + 1;
        } while (local_c < (int)unaff_EDI[9]);
      }
      local_10 = local_10 + 1;
    } while (local_10 < (int)unaff_EDI[6]);
  }
  return;
}

