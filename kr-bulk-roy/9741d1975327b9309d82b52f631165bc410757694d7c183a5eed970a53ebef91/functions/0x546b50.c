
undefined4 FUN_00546b50(int *param_1,char *param_2,int param_3)

{
  int iVar1;
  char cVar2;
  char cVar3;
  int in_EAX;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 extraout_ECX;
  float10 fVar9;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  
  if (DAT_00fba80c == 0) {
    iVar4 = FUN_00891268(0x57c);
    if (iVar4 == 0) {
      DAT_00fba80c = 0;
    }
    else {
      DAT_00fba80c = FUN_006f1370();
    }
  }
  iVar1 = DAT_00fba80c;
  iVar4 = DAT_00fb1318;
  if ((((*(int *)(DAT_00fba80c + 0x20) != 0) && (*(char *)(DAT_00fba80c + 0x368) != '\0')) &&
      ((*(uint *)(DAT_00fb1318 + 0xc01c) >> 1 & 1) == 0)) &&
     ((*(byte *)(DAT_00fb1318 + 0xc01c) & 1) == 0)) {
    *(undefined4 *)(in_EAX + 0x7c) = 1;
    *(undefined4 *)(in_EAX + 0x80) = 0;
  }
  if (param_3 == 0) {
    iVar8 = iVar1 + 0x370;
    if (*(int *)(iVar1 + 0x20) != 0) {
      iVar8 = iVar1 + 0x360;
    }
    if ((*(char *)(iVar8 + 2) == '\0') || ((*(byte *)(iVar4 + 0xc01c) & 1) != 0)) {
      DAT_00fe1e20 = 0;
    }
    else if (DAT_00fe1e20 == 0) {
      DAT_00fe1e20 = 1;
      iVar4 = 1 - *(int *)(in_EAX + 0x80);
      *(int *)(in_EAX + 0x80) = iVar4;
      *(uint *)(in_EAX + 0x7c) = (uint)(iVar4 != 0);
    }
    if (*(int *)(in_EAX + 0x7c) != 0) {
      if (*(int *)(iVar1 + 0x20) == 0) {
        pcVar5 = (char *)(iVar1 + 0x370);
      }
      else {
        pcVar5 = (char *)(iVar1 + 0x360);
      }
      if ((*pcVar5 == '\0') && (*(int *)(in_EAX + 0x80) == 0)) {
        *(undefined4 *)(in_EAX + 0x7c) = 0;
        return 0;
      }
      iVar4 = FUN_00443dc0();
      if (*(int *)(iVar4 + 0x20) == 0) {
        iVar4 = iVar4 + 0x370;
      }
      else {
        iVar4 = iVar4 + 0x360;
      }
      if (*(char *)(iVar4 + 1) == '\0') {
        uVar6 = (**(code **)(*param_1 + 0x4c))();
        uVar7 = FUN_00434740(extraout_ECX,uVar6);
        FUN_0079a6b0(uVar7,uVar6);
        fStack_18 = (float)*(int *)(DAT_00fb1318 + 0xc00c) - fStack_10;
        fStack_14 = (float)*(int *)(DAT_00fb1318 + 0xc010) - fStack_c;
        D3DXVec2Normalize(&fStack_18,&fStack_18);
        fVar9 = (float10)FUN_008fedca();
        cVar2 = FUN_004bb450(3.1415927 - ((float)fVar9 + 1.5707964));
        iVar4 = FUN_00434740();
        cVar3 = FUN_004bb450(*(undefined4 *)(*(int *)(iVar4 + 0x40) + 0x20));
        *param_2 = cVar3 + cVar2;
      }
      return 1;
    }
  }
  else {
    *(undefined4 *)(in_EAX + 0x7c) = 0;
  }
  *(undefined4 *)(in_EAX + 0x80) = 0;
  return 0;
}

