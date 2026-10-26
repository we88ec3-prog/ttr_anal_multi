
void FUN_0074cb40(void)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uStack_74;
  int *piStack_70;
  int *piStack_6c;
  int iStack_64;
  int iStack_58;
  int local_54;
  int iStack_50;
  int iStack_4c;
  uint uStack_48;
  uint local_44;
  
  local_44 = DAT_00d61f20 ^ (uint)&uStack_74;
  FUN_00760c80();
  (**(code **)(*in_ECX + 0x178))(&local_54);
  piStack_70 = in_ECX + 0x3d;
  uStack_74 = 0;
  do {
    uVar5 = uStack_74;
    uVar3 = uStack_74 % 3;
    FUN_008ff2e0((double)((float)(int)uStack_74 / 3.0));
    iVar1 = FUN_008fed10();
    if ((uVar3 != 1) || (iVar1 != 1)) {
      if (iVar1 == 0) {
        iStack_64 = 0;
        iVar1 = local_54;
      }
      else if (iVar1 == 1) {
        iStack_64 = local_54;
        iVar1 = iStack_4c;
      }
      else {
        iVar1 = in_ECX[5] - in_ECX[3];
        iStack_64 = iStack_4c;
      }
      if (uVar3 == 0) {
        iVar2 = iStack_58;
        iVar4 = 0;
      }
      else {
        iVar2 = iStack_50;
        iVar4 = iStack_58;
        if (uVar3 != 1) {
          iVar2 = in_ECX[4] - in_ECX[2];
          iVar4 = iStack_50;
        }
      }
      (**(code **)(*(int *)*piStack_70 + 0xbc))(iVar4,iStack_64,iVar2,iVar1);
      piStack_70 = piStack_70 + 1;
      in_ECX = piStack_6c;
      uVar5 = uStack_74;
    }
    uStack_74 = uVar5 + 1;
  } while ((int)uStack_74 < 9);
  __security_check_cookie(uStack_48 ^ (uint)&stack0xffffff88);
  return;
}

