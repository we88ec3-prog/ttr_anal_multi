
uint FUN_0072b070(uint param_1)

{
  byte *in_EAX;
  int iVar1;
  uint uVar2;
  uint in_ECX;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  
  uVar20 = in_ECX >> 0x10;
  uVar3 = in_ECX & 0xffff;
  if (param_1 == 1) {
    uVar3 = uVar3 + *in_EAX;
    if (0xfff0 < uVar3) {
      uVar3 = uVar3 - 0xfff1;
    }
    uVar20 = uVar20 + uVar3;
    if (0xfff0 < uVar20) {
      return (uVar20 - 0xfff1) * 0x10000 | uVar3;
    }
  }
  else {
    if (in_EAX == (byte *)0x0) {
      return 1;
    }
    if (param_1 < 0x10) {
      for (; param_1 != 0; param_1 = param_1 - 1) {
        uVar3 = uVar3 + *in_EAX;
        in_EAX = in_EAX + 1;
        uVar20 = uVar20 + uVar3;
      }
      if (0xfff0 < uVar3) {
        uVar3 = uVar3 - 0xfff1;
      }
      return ((uVar20 / 0xfff1) * 0xf + uVar20) * 0x10000 | uVar3;
    }
    uVar19 = param_1;
    if (0x15af < param_1) {
      param_1 = param_1 / 0x15b0;
      do {
        uVar19 = uVar19 - 0x15b0;
        iVar1 = 0x15b;
        do {
          iVar4 = uVar3 + *in_EAX;
          iVar5 = iVar4 + (uint)in_EAX[1];
          iVar6 = iVar5 + (uint)in_EAX[2];
          iVar7 = iVar6 + (uint)in_EAX[3];
          iVar8 = iVar7 + (uint)in_EAX[4];
          iVar9 = iVar8 + (uint)in_EAX[5];
          iVar10 = iVar9 + (uint)in_EAX[6];
          iVar11 = iVar10 + (uint)in_EAX[7];
          iVar12 = iVar11 + (uint)in_EAX[8];
          iVar13 = iVar12 + (uint)in_EAX[9];
          iVar14 = iVar13 + (uint)in_EAX[10];
          iVar15 = iVar14 + (uint)in_EAX[0xb];
          iVar16 = iVar15 + (uint)in_EAX[0xc];
          iVar17 = iVar16 + (uint)in_EAX[0xd];
          iVar18 = iVar17 + (uint)in_EAX[0xe];
          uVar3 = iVar18 + (uint)in_EAX[0xf];
          uVar20 = uVar20 + iVar4 + iVar5 + iVar6 + iVar7 + iVar8 + iVar9 + iVar10 + iVar11 + iVar12
                   + iVar13 + iVar14 + iVar15 + iVar16 + iVar17 + iVar18 + uVar3;
          in_EAX = in_EAX + 0x10;
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
        uVar3 = uVar3 % 0xfff1;
        uVar20 = uVar20 % 0xfff1;
        param_1 = param_1 - 1;
      } while (param_1 != 0);
    }
    if (uVar19 != 0) {
      if (0xf < uVar19) {
        uVar2 = uVar19 >> 4;
        do {
          iVar1 = uVar3 + *in_EAX;
          iVar4 = iVar1 + (uint)in_EAX[1];
          iVar5 = iVar4 + (uint)in_EAX[2];
          iVar6 = iVar5 + (uint)in_EAX[3];
          iVar7 = iVar6 + (uint)in_EAX[4];
          iVar8 = iVar7 + (uint)in_EAX[5];
          iVar9 = iVar8 + (uint)in_EAX[6];
          iVar10 = iVar9 + (uint)in_EAX[7];
          iVar11 = iVar10 + (uint)in_EAX[8];
          iVar12 = iVar11 + (uint)in_EAX[9];
          iVar13 = iVar12 + (uint)in_EAX[10];
          iVar14 = iVar13 + (uint)in_EAX[0xb];
          iVar15 = iVar14 + (uint)in_EAX[0xc];
          iVar16 = iVar15 + (uint)in_EAX[0xd];
          iVar17 = iVar16 + (uint)in_EAX[0xe];
          uVar3 = iVar17 + (uint)in_EAX[0xf];
          uVar19 = uVar19 - 0x10;
          uVar20 = uVar20 + iVar1 + iVar4 + iVar5 + iVar6 + iVar7 + iVar8 + iVar9 + iVar10 + iVar11
                   + iVar12 + iVar13 + iVar14 + iVar15 + iVar16 + iVar17 + uVar3;
          in_EAX = in_EAX + 0x10;
          uVar2 = uVar2 - 1;
        } while (uVar2 != 0);
      }
      for (; uVar19 != 0; uVar19 = uVar19 - 1) {
        uVar3 = uVar3 + *in_EAX;
        in_EAX = in_EAX + 1;
        uVar20 = uVar20 + uVar3;
      }
      uVar3 = uVar3 % 0xfff1;
      uVar20 = uVar20 % 0xfff1;
    }
  }
  return uVar20 << 0x10 | uVar3;
}

