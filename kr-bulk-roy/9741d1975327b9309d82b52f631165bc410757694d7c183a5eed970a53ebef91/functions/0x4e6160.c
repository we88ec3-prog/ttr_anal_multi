
void FUN_004e6160(void)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  int *piVar3;
  
  (**(code **)(*in_ECX + 8))();
  piVar3 = in_ECX + 0x12;
  piVar1 = piVar3;
  if (0xf < (uint)in_ECX[0x17]) {
    piVar1 = (int *)*piVar3;
  }
  iVar2 = FUN_00734330(piVar1,0);
  in_ECX[0x11] = iVar2;
  if (iVar2 == 0) {
    if (0xf < (uint)in_ECX[0x17]) {
      piVar3 = (int *)*piVar3;
    }
    FUN_006edb60("CTeamRankUpEffect::Load(): Can\'t load texture file \'%s\'",piVar3);
  }
  in_ECX[0xd] = 1;
  return;
}

