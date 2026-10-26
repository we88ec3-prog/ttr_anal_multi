
void FUN_006ec5c0(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *unaff_EDI;
  int local_8;
  
  local_8 = 0;
  if (0 < (int)param_1[5]) {
    do {
      uVar1 = *(undefined4 *)(param_1[4] + local_8 * 4);
      iVar2 = (**(code **)(*(int *)*param_1 + 0x28))
                        ((int *)*param_1,*unaff_EDI,unaff_EDI[1],unaff_EDI[2],2,1,uVar1);
      if ((-1 < iVar2) &&
         (iVar2 = (**(code **)(*(int *)*param_1 + 0x30))
                            ((int *)*param_1,*unaff_EDI,unaff_EDI[1],unaff_EDI[2],unaff_EDI[3],uVar1
                            ), -1 < iVar2)) {
        iVar2 = FUN_006ed1c0();
        if (-1 < iVar2) {
          *(undefined4 *)(unaff_EDI[5] + unaff_EDI[6] * 4) = uVar1;
          unaff_EDI[6] = unaff_EDI[6] + 1;
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < (int)param_1[5]);
  }
  return;
}

