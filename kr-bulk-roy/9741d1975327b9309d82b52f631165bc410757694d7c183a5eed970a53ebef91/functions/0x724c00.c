
void FUN_00724c00(uint param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  int *unaff_ESI;
  undefined1 local_30 [4];
  int *local_2c;
  int *local_28;
  int local_20;
  int local_1c [3];
  int local_10;
  int local_c [2];
  
  iVar1 = param_2;
  iVar3 = *(int *)(param_1 + 4);
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  *unaff_ESI = 2;
  if (iVar3 == 0) {
    piVar2 = in_ECX;
    if (in_ECX[1] != 0) {
      param_2 = 0;
      piVar2 = &param_2;
    }
    if (*piVar2 == 0) {
      FUN_00721400();
      FUN_00726680(param_1);
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
    if (local_2c != local_28) {
      do {
        local_20 = unaff_ESI[2] - unaff_ESI[1] >> 3;
        if (local_20 != 0) {
          *unaff_ESI = 0;
        }
        iVar3 = local_2c[1];
        piVar2 = local_2c;
        if (iVar3 != 0) {
          param_2 = 0;
          piVar2 = &param_2;
        }
        if (*piVar2 == 0) {
          piVar2 = local_2c;
          if (iVar3 == 0) {
            if (*local_2c == 0) {
              local_1c[1] = 0;
              piVar2 = local_1c + 1;
            }
            else {
              local_1c[2] = *(undefined4 *)(*local_2c + 4);
              piVar2 = local_1c + 2;
            }
            local_1c[0] = *piVar2;
            piVar2 = local_1c;
          }
          local_10 = *piVar2;
        }
        else {
          piVar2 = local_2c;
          if (iVar3 != 0) {
            local_c[0] = 0;
            piVar2 = local_c;
          }
          local_10 = *piVar2;
        }
        FUN_00726680(param_1);
        FUN_0071d5a0(unaff_ESI,local_20,iVar1);
        local_2c = local_2c + 2;
      } while (local_2c != local_28);
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

