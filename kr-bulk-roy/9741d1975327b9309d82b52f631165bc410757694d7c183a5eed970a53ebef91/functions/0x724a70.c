
void FUN_00724a70(uint param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *in_ECX;
  int *unaff_ESI;
  undefined1 local_30 [4];
  int *local_2c;
  int *local_28;
  int local_20;
  int local_1c [3];
  int local_10 [3];
  
  iVar1 = param_2;
  iVar3 = *(int *)(param_1 + 4);
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  *unaff_ESI = 1;
  if (iVar3 == 0) {
    piVar4 = in_ECX;
    if (in_ECX[1] != 0) {
      param_2 = 0;
      piVar4 = &param_2;
    }
    if (*piVar4 == 0) {
      uVar5 = FUN_00721400();
      FUN_0071d780(unaff_ESI,uVar5);
      FUN_0071d5a0(unaff_ESI,0,iVar1);
    }
    else {
      if (in_ECX[1] != 0) {
        param_2 = 0;
        in_ECX = &param_2;
      }
      param_2 = *in_ECX;
      FUN_00726680(param_1);
      FUN_0071d5a0(unaff_ESI,0,iVar1);
    }
  }
  else {
    FUN_0071efc0(local_30,in_ECX,param_2);
    piVar4 = local_2c;
    if (local_2c != local_28) {
      do {
        local_20 = unaff_ESI[2] - unaff_ESI[1] >> 3;
        if (local_20 != 0) {
          *unaff_ESI = 0;
        }
        iVar3 = piVar4[1];
        piVar2 = piVar4;
        if (iVar3 != 0) {
          param_2 = 0;
          piVar2 = &param_2;
        }
        if (*piVar2 == 0) {
          piVar2 = piVar4;
          if (iVar3 == 0) {
            if (*piVar4 == 0) {
              local_1c[1] = 0;
              piVar2 = local_1c + 1;
            }
            else {
              local_1c[2] = *(undefined4 *)(*piVar4 + 4);
              piVar2 = local_1c + 2;
            }
            local_1c[0] = *piVar2;
            piVar2 = local_1c;
          }
          local_10[0] = *piVar2;
          FUN_0071d780(unaff_ESI,local_10);
        }
        else {
          piVar2 = piVar4;
          if (iVar3 != 0) {
            local_10[1] = 0;
            piVar2 = local_10 + 1;
          }
          local_10[0] = *piVar2;
          FUN_00726680(param_1);
        }
        FUN_0071d5a0(unaff_ESI,local_20,iVar1);
        piVar4 = piVar4 + 2;
      } while (piVar4 != local_28);
    }
  }
  if (*unaff_ESI == 0) {
    param_1 = param_1 & 0xffffff;
    FUN_00722b30(unaff_ESI[1],unaff_ESI[2],(int)&param_1 + 3);
    iVar3 = FUN_00722bd0();
    unaff_ESI[2] = iVar3;
  }
  return;
}

