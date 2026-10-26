
void FUN_007245f0(uint param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  int *piVar4;
  int *unaff_ESI;
  int unaff_EDI;
  undefined1 local_34 [4];
  int *local_30;
  int *local_2c;
  int local_24;
  int local_20 [3];
  int local_14 [4];
  
  iVar3 = *(int *)(unaff_EDI + 4);
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  *unaff_ESI = 1;
  if (iVar3 == 0) {
    iVar3 = in_ECX[1];
    piVar4 = in_ECX;
    if (iVar3 != 0) {
      local_24 = 0;
      piVar4 = &local_24;
    }
    if (*piVar4 == 0) {
      local_24 = iVar3;
      uVar2 = FUN_00721400();
      if (*(char *)(unaff_EDI + 3) == '\x02') {
        FUN_0071d6a0(unaff_EDI,unaff_ESI,&local_24,uVar2);
      }
    }
    else {
      if (iVar3 != 0) {
        local_24 = 0;
        in_ECX = &local_24;
      }
      local_24 = *in_ECX;
      FUN_007260e0();
    }
    FUN_0071d5a0(unaff_ESI,0,param_1);
  }
  else {
    FUN_0071efc0(local_34,in_ECX,param_1);
    piVar4 = local_30;
    if (local_30 != local_2c) {
      do {
        local_14[3] = unaff_ESI[2] - unaff_ESI[1] >> 3;
        if (local_14[3] != 0) {
          *unaff_ESI = 0;
        }
        iVar3 = piVar4[1];
        piVar1 = piVar4;
        if (iVar3 != 0) {
          local_14[2] = 0;
          piVar1 = local_14 + 2;
        }
        if (*piVar1 == 0) {
          piVar1 = piVar4;
          if (iVar3 == 0) {
            if (*piVar4 == 0) {
              local_20[1] = 0;
              piVar1 = local_20 + 1;
            }
            else {
              local_20[2] = *(undefined4 *)(*piVar4 + 4);
              piVar1 = local_20 + 2;
            }
            local_20[0] = *piVar1;
            piVar1 = local_20;
          }
          local_14[0] = *piVar1;
          local_24 = iVar3;
          if (*(char *)(unaff_EDI + 3) == '\x02') {
            FUN_0071d6a0(unaff_EDI,unaff_ESI,&local_24,local_14);
          }
        }
        else {
          piVar1 = piVar4;
          if (iVar3 != 0) {
            local_14[1] = 0;
            piVar1 = local_14 + 1;
          }
          local_14[0] = *piVar1;
          FUN_007260e0();
        }
        FUN_0071d5a0(unaff_ESI,local_14[3],param_1);
        piVar4 = piVar4 + 2;
      } while (piVar4 != local_2c);
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

