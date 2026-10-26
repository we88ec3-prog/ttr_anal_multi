
void FUN_007247a0(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  int *piVar3;
  int iVar4;
  int *unaff_ESI;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 local_34 [4];
  int *local_30;
  int *local_2c;
  int local_24;
  int local_20 [3];
  int local_14;
  int local_10 [3];
  
  iVar1 = param_1;
  iVar4 = *(int *)(param_1 + 4);
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  *unaff_ESI = 1;
  if (iVar4 == 0) {
    iVar4 = in_ECX[1];
    piVar3 = in_ECX;
    if (iVar4 != 0) {
      param_1 = 0;
      piVar3 = &param_1;
    }
    if (*piVar3 == 0) {
      uVar5 = *param_2;
      param_1 = iVar4;
      uVar6 = param_3;
      FUN_00721400(uVar5,param_3);
      FUN_007265d0(iVar1,unaff_ESI,uVar5,uVar6);
    }
    else {
      if (iVar4 != 0) {
        param_1 = 0;
        in_ECX = &param_1;
      }
      param_1 = *in_ECX;
      FUN_00726680(iVar1);
    }
    FUN_0071d5a0(unaff_ESI,0,param_2);
  }
  else {
    FUN_0071efc0(local_34,in_ECX,param_2);
    piVar3 = local_30;
    if (local_30 != local_2c) {
      do {
        iVar4 = unaff_ESI[2] - unaff_ESI[1] >> 3;
        if (iVar4 != 0) {
          *unaff_ESI = 0;
        }
        iVar1 = piVar3[1];
        piVar2 = piVar3;
        if (iVar1 != 0) {
          local_10[1] = 0;
          piVar2 = local_10 + 1;
        }
        if (*piVar2 == 0) {
          piVar2 = piVar3;
          if (iVar1 == 0) {
            if (*piVar3 == 0) {
              local_20[1] = 0;
              piVar2 = local_20 + 1;
            }
            else {
              local_20[2] = *(undefined4 *)(*piVar3 + 4);
              piVar2 = local_20 + 2;
            }
            local_20[0] = *piVar2;
            piVar2 = local_20;
          }
          local_14 = *piVar2;
          local_24 = iVar1;
          FUN_007265d0(param_1,unaff_ESI,*param_2,param_3);
        }
        else {
          piVar2 = piVar3;
          if (iVar1 != 0) {
            local_10[0] = 0;
            piVar2 = local_10;
          }
          local_14 = *piVar2;
          FUN_00726680(param_1);
        }
        FUN_0071d5a0(unaff_ESI,iVar4,param_2);
        piVar3 = piVar3 + 2;
      } while (piVar3 != local_2c);
    }
  }
  if (*unaff_ESI == 0) {
    param_2 = (undefined4 *)((uint)param_2 & 0xffffff);
    FUN_00722b30(unaff_ESI[1],unaff_ESI[2],(int)&param_2 + 3);
    iVar4 = FUN_00722bd0();
    unaff_ESI[2] = iVar4;
  }
  return;
}

