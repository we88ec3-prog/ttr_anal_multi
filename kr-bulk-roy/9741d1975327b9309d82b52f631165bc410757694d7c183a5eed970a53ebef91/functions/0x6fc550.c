
void FUN_006fc550(int param_1,int param_2)

{
  double dVar1;
  double dVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  int iVar14;
  double *pdVar15;
  double *pdVar16;
  uint uVar17;
  uint *puVar18;
  int iVar19;
  double *pdVar20;
  float10 fVar21;
  uint *local_cc;
  int local_c8;
  double *local_c4;
  uint local_bc;
  double local_a0;
  double local_90;
  double local_88;
  undefined4 local_80 [2];
  undefined4 local_78;
  double local_70;
  undefined4 local_68;
  undefined4 local_60 [2];
  undefined4 local_58;
  double local_50;
  undefined4 local_48;
  
LAB_006fc562:
  local_c8 = *(int *)(param_1 + 0xc);
  iVar11 = **(int **)(*(int *)(param_1 + 0x14) + 4);
  iVar14 = *(int *)(*(int *)(iVar11 + 0x10) + 8);
  puVar18 = *(uint **)(param_1 + 0x18);
switchD_006fc5f1_default:
  local_cc = puVar18;
  uVar17 = *local_cc;
  puVar18 = local_cc + 1;
  if ((*(byte *)(param_1 + 0x38) & 0xc) != 0) {
    piVar7 = (int *)(param_1 + 0x40);
    *piVar7 = *piVar7 + -1;
    if ((*piVar7 == 0) || ((*(byte *)(param_1 + 0x38) & 4) != 0)) {
      FUN_006fb660();
      if (*(char *)(param_1 + 6) == '\x01') {
        *(uint **)(param_1 + 0x18) = local_cc;
        return;
      }
      local_c8 = *(int *)(param_1 + 0xc);
    }
  }
  uVar4 = uVar17 >> 6 & 0xff;
  iVar5 = uVar4 * 0x10;
  pdVar20 = (double *)(iVar5 + local_c8);
  switch(uVar17 & 0x3f) {
  case 0:
    puVar8 = (undefined4 *)((uVar17 >> 0x17) * 0x10 + local_c8);
    goto LAB_006fc600;
  case 1:
    puVar8 = (undefined4 *)((uVar17 >> 0xe) * 0x10 + iVar14);
LAB_006fc600:
    *(undefined4 *)pdVar20 = *puVar8;
    *(undefined4 *)((int)pdVar20 + 4) = puVar8[1];
    *(undefined4 *)(pdVar20 + 1) = puVar8[2];
    goto switchD_006fc5f1_default;
  case 2:
    *(uint *)pdVar20 = uVar17 >> 0x17;
    *(undefined4 *)(pdVar20 + 1) = 1;
    if ((uVar17 & 0x7fc000) != 0) {
      puVar18 = local_cc + 2;
    }
    goto switchD_006fc5f1_default;
  case 3:
    pdVar16 = (double *)((uVar17 >> 0x17) * 0x10 + local_c8);
    do {
      *(undefined4 *)(pdVar16 + 1) = 0;
      pdVar16 = pdVar16 + -2;
    } while (pdVar20 <= pdVar16);
    goto switchD_006fc5f1_default;
  case 4:
    puVar8 = *(undefined4 **)(*(int *)(iVar11 + 0x14 + (uVar17 >> 0x17) * 4) + 8);
    *(undefined4 *)pdVar20 = *puVar8;
    *(undefined4 *)((int)pdVar20 + 4) = puVar8[1];
    *(undefined4 *)(pdVar20 + 1) = puVar8[2];
    goto switchD_006fc5f1_default;
  case 5:
    local_80[0] = *(undefined4 *)(iVar11 + 0xc);
    local_78 = 5;
    *(uint **)(param_1 + 0x18) = puVar18;
    FUN_006fb850(param_1,local_80);
    local_c8 = *(int *)(param_1 + 0xc);
    goto switchD_006fc5f1_default;
  case 6:
    *(uint **)(param_1 + 0x18) = puVar18;
    FUN_006fb850(param_1,(uVar17 >> 0x17) * 0x10 + local_c8);
    local_c8 = *(int *)(param_1 + 0xc);
    goto switchD_006fc5f1_default;
  case 7:
    local_60[0] = *(undefined4 *)(iVar11 + 0xc);
    local_58 = 5;
    *(uint **)(param_1 + 0x18) = puVar18;
    FUN_006fb9a0(param_1,local_60);
    local_c8 = *(int *)(param_1 + 0xc);
    goto switchD_006fc5f1_default;
  case 8:
    iVar5 = *(int *)(iVar11 + 0x14 + (uVar17 >> 0x17) * 4);
    puVar8 = *(undefined4 **)(iVar5 + 8);
    *puVar8 = *(undefined4 *)pdVar20;
    puVar8[1] = *(undefined4 *)((int)pdVar20 + 4);
    puVar8[2] = *(undefined4 *)(pdVar20 + 1);
    if (((3 < *(int *)(pdVar20 + 1)) && ((*(byte *)(*(int *)pdVar20 + 5) & 3) != 0)) &&
       ((*(byte *)(iVar5 + 5) & 4) != 0)) {
      if (*(char *)(*(int *)(param_1 + 0x10) + 0x15) == '\x01') {
        FUN_006f9f70();
      }
      else {
        *(byte *)(iVar5 + 5) =
             *(byte *)(*(int *)(param_1 + 0x10) + 0x14) & 3 | *(byte *)(iVar5 + 5) & 0xf8;
      }
    }
    goto switchD_006fc5f1_default;
  case 9:
    *(uint **)(param_1 + 0x18) = puVar18;
    FUN_006fb9a0(param_1,pdVar20);
    local_c8 = *(int *)(param_1 + 0xc);
    goto switchD_006fc5f1_default;
  case 10:
    uVar10 = FUN_006f99a0(param_1);
    *(undefined4 *)pdVar20 = uVar10;
    *(undefined4 *)(pdVar20 + 1) = 5;
    *(uint **)(param_1 + 0x18) = puVar18;
    if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    local_c8 = *(int *)(param_1 + 0xc);
    goto switchD_006fc5f1_default;
  case 0xb:
    iVar5 = (uVar17 >> 0x17) * 0x10;
    iVar9 = iVar5 + local_c8;
    *(undefined4 *)(pdVar20 + 2) = *(undefined4 *)(iVar5 + local_c8);
    *(undefined4 *)((int)pdVar20 + 0x14) = *(undefined4 *)(iVar9 + 4);
    *(undefined4 *)(pdVar20 + 3) = *(undefined4 *)(iVar9 + 8);
    *(uint **)(param_1 + 0x18) = puVar18;
    FUN_006fb850(param_1,iVar9);
    local_c8 = *(int *)(param_1 + 0xc);
    goto switchD_006fc5f1_default;
  case 0xc:
    uVar4 = uVar17 >> 0x17;
    if ((uVar4 & 0x100) == 0) {
      pdVar16 = (double *)(uVar4 * 0x10 + local_c8);
    }
    else {
      pdVar16 = (double *)((uVar4 & 0xff) * 0x10 + iVar14);
    }
    uVar17 = uVar17 >> 0xe;
    if ((uVar17 & 0x100) == 0) {
      pdVar15 = (double *)((uVar17 & 0x1ff) * 0x10 + local_c8);
    }
    else {
      pdVar15 = (double *)((uVar17 & 0xff) * 0x10 + iVar14);
    }
    if ((*(int *)(pdVar16 + 1) == 3) && (*(int *)(pdVar15 + 1) == 3)) {
      dVar2 = *pdVar15;
      dVar1 = *pdVar16;
      *(undefined4 *)(pdVar20 + 1) = 3;
      *pdVar20 = dVar2 + dVar1;
      goto switchD_006fc5f1_default;
    }
    break;
  case 0xd:
    uVar4 = uVar17 >> 0x17;
    if ((uVar4 & 0x100) == 0) {
      pdVar16 = (double *)(uVar4 * 0x10 + local_c8);
    }
    else {
      pdVar16 = (double *)((uVar4 & 0xff) * 0x10 + iVar14);
    }
    uVar17 = uVar17 >> 0xe;
    if ((uVar17 & 0x100) == 0) {
      pdVar15 = (double *)((uVar17 & 0x1ff) * 0x10 + local_c8);
    }
    else {
      pdVar15 = (double *)((uVar17 & 0xff) * 0x10 + iVar14);
    }
    if ((*(int *)(pdVar16 + 1) == 3) && (*(int *)(pdVar15 + 1) == 3)) {
      dVar2 = *pdVar16;
      dVar1 = *pdVar15;
      *(undefined4 *)(pdVar20 + 1) = 3;
      *pdVar20 = dVar2 - dVar1;
      goto switchD_006fc5f1_default;
    }
    break;
  case 0xe:
    uVar4 = uVar17 >> 0x17;
    if ((uVar4 & 0x100) == 0) {
      pdVar16 = (double *)(uVar4 * 0x10 + local_c8);
    }
    else {
      pdVar16 = (double *)((uVar4 & 0xff) * 0x10 + iVar14);
    }
    uVar17 = uVar17 >> 0xe;
    if ((uVar17 & 0x100) == 0) {
      pdVar15 = (double *)((uVar17 & 0x1ff) * 0x10 + local_c8);
    }
    else {
      pdVar15 = (double *)((uVar17 & 0xff) * 0x10 + iVar14);
    }
    if ((*(int *)(pdVar16 + 1) == 3) && (*(int *)(pdVar15 + 1) == 3)) {
      dVar2 = *pdVar15;
      dVar1 = *pdVar16;
      *(undefined4 *)(pdVar20 + 1) = 3;
      *pdVar20 = dVar2 * dVar1;
      goto switchD_006fc5f1_default;
    }
    break;
  case 0xf:
    uVar4 = uVar17 >> 0x17;
    if ((uVar4 & 0x100) == 0) {
      pdVar16 = (double *)(uVar4 * 0x10 + local_c8);
    }
    else {
      pdVar16 = (double *)((uVar4 & 0xff) * 0x10 + iVar14);
    }
    uVar17 = uVar17 >> 0xe;
    if ((uVar17 & 0x100) == 0) {
      pdVar15 = (double *)((uVar17 & 0x1ff) * 0x10 + local_c8);
    }
    else {
      pdVar15 = (double *)((uVar17 & 0xff) * 0x10 + iVar14);
    }
    if ((*(int *)(pdVar16 + 1) == 3) && (*(int *)(pdVar15 + 1) == 3)) {
      dVar2 = *pdVar16;
      dVar1 = *pdVar15;
      *(undefined4 *)(pdVar20 + 1) = 3;
      *pdVar20 = dVar2 / dVar1;
      goto switchD_006fc5f1_default;
    }
    break;
  case 0x10:
    uVar4 = uVar17 >> 0x17;
    if ((uVar4 & 0x100) == 0) {
      pdVar16 = (double *)(uVar4 * 0x10 + local_c8);
    }
    else {
      pdVar16 = (double *)((uVar4 & 0xff) * 0x10 + iVar14);
    }
    uVar17 = uVar17 >> 0xe;
    if ((uVar17 & 0x100) == 0) {
      pdVar15 = (double *)((uVar17 & 0x1ff) * 0x10 + local_c8);
    }
    else {
      pdVar15 = (double *)((uVar17 & 0xff) * 0x10 + iVar14);
    }
    if ((*(int *)(pdVar16 + 1) == 3) && (*(int *)(pdVar15 + 1) == 3)) {
      dVar2 = *pdVar16;
      dVar1 = *pdVar15;
      fVar21 = (float10)FUN_008ff2e0();
      *(undefined4 *)(pdVar20 + 1) = 3;
      *pdVar20 = (double)((float10)dVar2 - fVar21 * (float10)dVar1);
      goto switchD_006fc5f1_default;
    }
    break;
  case 0x11:
    uVar4 = uVar17 >> 0x17;
    if ((uVar4 & 0x100) == 0) {
      pdVar16 = (double *)(uVar4 * 0x10 + local_c8);
    }
    else {
      pdVar16 = (double *)((uVar4 & 0xff) * 0x10 + iVar14);
    }
    uVar17 = uVar17 >> 0xe;
    if ((uVar17 & 0x100) == 0) {
      iVar5 = (uVar17 & 0x1ff) * 0x10 + local_c8;
    }
    else {
      iVar5 = (uVar17 & 0xff) * 0x10 + iVar14;
    }
    if ((*(int *)(pdVar16 + 1) == 3) && (*(int *)(iVar5 + 8) == 3)) {
      fVar21 = (float10)FUN_008ff5a0();
      *pdVar20 = (double)fVar21;
      *(undefined4 *)(pdVar20 + 1) = 3;
      goto switchD_006fc5f1_default;
    }
    break;
  case 0x12:
    pdVar16 = (double *)((uVar17 >> 0x17) * 0x10 + local_c8);
    if (*(int *)(pdVar16 + 1) != 3) {
      *(uint **)(param_1 + 0x18) = puVar18;
      local_c4 = pdVar16;
      if (*(int *)(pdVar16 + 1) == 3) {
LAB_006fcc19:
        if ((*(int *)(pdVar16 + 1) == 3) ||
           ((*(int *)(pdVar16 + 1) == 4 && (iVar5 = FUN_006f7760(), iVar5 != 0)))) {
          *pdVar20 = -*local_c4;
          *(undefined4 *)(pdVar20 + 1) = 3;
          local_c8 = *(int *)(param_1 + 0xc);
          goto switchD_006fc5f1_default;
        }
      }
      else if ((*(int *)(pdVar16 + 1) == 4) && (iVar5 = FUN_006f7760(), iVar5 != 0)) {
        local_68 = 3;
        local_c4 = &local_70;
        goto LAB_006fcc19;
      }
      iVar5 = FUN_006fbb80(param_1,pdVar16,pdVar16);
      if (iVar5 == 0) {
        if ((*(int *)(pdVar16 + 1) != 3) && (*(int *)(pdVar16 + 1) == 4)) {
          FUN_006f7760();
        }
        FUN_006f8970();
      }
      local_c8 = *(int *)(param_1 + 0xc);
      goto switchD_006fc5f1_default;
    }
    dVar2 = *pdVar16;
    *(undefined4 *)(pdVar20 + 1) = 3;
    *pdVar20 = -dVar2;
    goto switchD_006fc5f1_default;
  case 0x13:
    iVar5 = *(int *)(local_c8 + 8 + (uVar17 >> 0x17) * 0x10);
    if ((iVar5 == 0) || ((iVar5 == 1 && (*(int *)(local_c8 + (uVar17 >> 0x17) * 0x10) == 0)))) {
      *(undefined4 *)pdVar20 = 1;
      *(undefined4 *)(pdVar20 + 1) = 1;
    }
    else {
      *(undefined4 *)pdVar20 = 0;
      *(undefined4 *)(pdVar20 + 1) = 1;
    }
    goto switchD_006fc5f1_default;
  case 0x14:
    iVar9 = (uVar17 >> 0x17) * 0x10;
    iVar5 = *(int *)(iVar9 + 8 + local_c8);
    piVar7 = (int *)(iVar9 + local_c8);
    if (iVar5 == 4) {
      iVar5 = *piVar7;
      dVar2 = (double)*(int *)(iVar5 + 0xc);
      if (*(int *)(iVar5 + 0xc) < 0) {
        dVar2 = dVar2 + 4294967296.0;
      }
      *pdVar20 = dVar2;
      *(undefined4 *)(pdVar20 + 1) = 3;
    }
    else if (iVar5 == 5) {
      iVar5 = FUN_006f9f10();
      *(undefined4 *)(pdVar20 + 1) = 3;
      *pdVar20 = (double)iVar5;
    }
    else {
      *(uint **)(param_1 + 0x18) = puVar18;
      iVar5 = FUN_006fbb80(param_1,piVar7,&DAT_00c0bfc8);
      if (iVar5 == 0) {
        FUN_006f8970();
      }
      local_c8 = *(int *)(param_1 + 0xc);
    }
    goto switchD_006fc5f1_default;
  case 0x15:
    uVar17 = uVar17 >> 0x17;
    *(uint **)(param_1 + 0x18) = puVar18;
    FUN_006fc080(param_1);
    if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    local_c8 = *(int *)(param_1 + 0xc);
    *(undefined4 *)(iVar5 + local_c8) = *(undefined4 *)(local_c8 + uVar17 * 0x10);
    *(undefined4 *)(iVar5 + 4 + local_c8) = *(undefined4 *)(local_c8 + 4 + uVar17 * 0x10);
    *(undefined4 *)(iVar5 + 8 + local_c8) = *(undefined4 *)(local_c8 + 8 + uVar17 * 0x10);
    goto switchD_006fc5f1_default;
  case 0x16:
    puVar18 = local_cc + ((uVar17 >> 0xe) - 0x1fffe);
    goto switchD_006fc5f1_default;
  case 0x17:
    uVar6 = uVar17 >> 0x17;
    if ((uVar6 & 0x100) == 0) {
      iVar5 = uVar6 * 0x10 + local_c8;
    }
    else {
      iVar5 = (uVar6 & 0xff) * 0x10 + iVar14;
    }
    uVar17 = uVar17 >> 0xe;
    if ((uVar17 & 0x100) == 0) {
      local_c8 = (uVar17 & 0x1ff) * 0x10 + local_c8;
    }
    else {
      local_c8 = (uVar17 & 0xff) * 0x10 + iVar14;
    }
    *(uint **)(param_1 + 0x18) = puVar18;
    if ((*(int *)(iVar5 + 8) == *(int *)(local_c8 + 8)) && (iVar5 = FUN_006fbfa0(), iVar5 != 0)) {
      uVar17 = 1;
    }
    else {
      uVar17 = 0;
    }
    if (uVar17 == uVar4) {
      puVar18 = local_cc + ((*puVar18 >> 0xe) - 0x1fffe);
    }
    local_cc = puVar18;
    local_c8 = *(int *)(param_1 + 0xc);
    puVar18 = local_cc + 1;
    goto switchD_006fc5f1_default;
  case 0x18:
    *(uint **)(param_1 + 0x18) = puVar18;
    uVar17 = FUN_006fbe20();
    if (uVar17 != uVar4) goto LAB_006fcf83;
    local_c8 = *(int *)(param_1 + 0xc);
    puVar18 = local_cc + ((*puVar18 >> 0xe) - 0x1fffd);
    goto switchD_006fc5f1_default;
  case 0x19:
    *(uint **)(param_1 + 0x18) = puVar18;
    uVar17 = FUN_006fbed0();
    if (uVar17 == uVar4) {
      puVar18 = local_cc + ((*puVar18 >> 0xe) - 0x1fffe);
    }
LAB_006fcf83:
    local_cc = puVar18;
    local_c8 = *(int *)(param_1 + 0xc);
    puVar18 = local_cc + 1;
    goto switchD_006fc5f1_default;
  case 0x1a:
    if ((*(int *)(pdVar20 + 1) == 0) || ((*(int *)(pdVar20 + 1) == 1 && (*(int *)pdVar20 == 0)))) {
      uVar4 = 1;
    }
    else {
      uVar4 = 0;
    }
    if (uVar4 != (uVar17 >> 0xe & 0x1ff)) {
LAB_006fd000:
      puVar18 = local_cc + ((*puVar18 >> 0xe) - 0x1fffe);
    }
    goto LAB_006fd014;
  case 0x1b:
    piVar7 = (int *)((uVar17 >> 0x17) * 0x10 + local_c8);
    if ((piVar7[2] == 0) || ((piVar7[2] == 1 && (*piVar7 == 0)))) {
      uVar4 = 1;
    }
    else {
      uVar4 = 0;
    }
    if (uVar4 != (uVar17 >> 0xe & 0x1ff)) {
      *(int *)pdVar20 = *piVar7;
      *(int *)((int)pdVar20 + 4) = piVar7[1];
      *(int *)(pdVar20 + 1) = piVar7[2];
      goto LAB_006fd000;
    }
LAB_006fd014:
    local_cc = puVar18;
    puVar18 = local_cc + 1;
    goto switchD_006fc5f1_default;
  case 0x1c:
    if (uVar17 >> 0x17 != 0) {
      *(double **)(param_1 + 8) = pdVar20 + (uVar17 >> 0x17) * 2;
    }
    *(uint **)(param_1 + 0x18) = puVar18;
    iVar5 = FUN_006fe1c0();
    if (iVar5 == 0) {
      param_2 = param_2 + 1;
      goto LAB_006fc562;
    }
    if (iVar5 != 1) {
      return;
    }
    if (-1 < (int)((uVar17 >> 0xe & 0x1ff) - 1)) {
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)(param_1 + 0x14) + 8);
    }
    local_c8 = *(int *)(param_1 + 0xc);
    goto switchD_006fc5f1_default;
  case 0x1d:
    if (uVar17 >> 0x17 != 0) {
      *(double **)(param_1 + 8) = pdVar20 + (uVar17 >> 0x17) * 2;
    }
    *(uint **)(param_1 + 0x18) = puVar18;
    iVar5 = FUN_006fe1c0();
    if (iVar5 != 0) {
      if (iVar5 != 1) {
        return;
      }
      local_c8 = *(int *)(param_1 + 0xc);
      goto switchD_006fc5f1_default;
    }
    piVar7 = *(int **)(param_1 + 0x14);
    puVar8 = (undefined4 *)piVar7[1];
    iVar11 = piVar7[-5];
    if (*(int *)(param_1 + 0x68) != 0) {
      FUN_006fd860();
    }
    iVar5 = piVar7[-5] + (*piVar7 - (int)puVar8 & 0xfffffff0U);
    piVar7[-6] = iVar5;
    iVar14 = 0;
    *(int *)(param_1 + 0xc) = iVar5;
    if (puVar8 < *(undefined4 **)(param_1 + 8)) {
      iVar5 = 0;
      puVar13 = puVar8;
      iVar14 = 0;
      do {
        *(undefined4 *)(iVar5 + iVar11) = *puVar13;
        *(undefined4 *)(iVar5 + 4 + iVar11) = puVar13[1];
        *(undefined4 *)(iVar5 + 8 + iVar11) = puVar13[2];
        iVar14 = iVar14 + 1;
        iVar5 = iVar14 * 0x10;
        puVar13 = puVar8 + iVar14 * 4;
      } while (puVar13 < *(undefined4 **)(param_1 + 8));
    }
    iVar11 = iVar11 + iVar14 * 0x10;
    *(int *)(param_1 + 8) = iVar11;
    piVar7[-4] = iVar11;
    iVar11 = *(int *)(param_1 + 0x18);
    piVar7[-1] = piVar7[-1] + 1;
    piVar7[-3] = iVar11;
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -0x18;
    goto LAB_006fc562;
  case 0x1e:
    goto switchD_006fc5f1_caseD_1e;
  case 0x1f:
    dVar1 = pdVar20[4] + *pdVar20;
    dVar2 = pdVar20[2];
    if (pdVar20[4] <= 0.0) {
      if (dVar1 < dVar2) goto switchD_006fc5f1_default;
    }
    else if (dVar1 < dVar2 == (dVar1 == dVar2)) goto switchD_006fc5f1_default;
    *pdVar20 = dVar1;
    *(undefined4 *)(pdVar20 + 1) = 3;
    pdVar20[6] = dVar1;
    *(undefined4 *)(pdVar20 + 7) = 3;
    puVar18 = local_cc + ((uVar17 >> 0xe) - 0x1fffe);
    goto switchD_006fc5f1_default;
  case 0x20:
    *(uint **)(param_1 + 0x18) = puVar18;
    local_c4 = pdVar20 + 4;
    if (*(int *)(pdVar20 + 1) == 3) {
LAB_006fd153:
      if (*(int *)(pdVar20 + 3) != 3) {
        if ((*(int *)(pdVar20 + 3) == 4) && (iVar5 = FUN_006f7760(), iVar5 != 0)) {
          pdVar20[2] = local_a0;
          *(undefined4 *)(pdVar20 + 3) = 3;
          if (pdVar20 + 2 != (double *)0x0) goto LAB_006fd19f;
        }
        goto LAB_006fd1e8;
      }
LAB_006fd19f:
      if (*(int *)(pdVar20 + 5) != 3) {
        if ((*(int *)(pdVar20 + 5) == 4) && (iVar5 = FUN_006f7760(), iVar5 != 0)) {
          *local_c4 = local_88;
          *(undefined4 *)(pdVar20 + 5) = 3;
          if (local_c4 != (double *)0x0) goto LAB_006fd1f0;
        }
        else {
          local_c4 = (double *)0x0;
        }
        goto LAB_006fd1e8;
      }
    }
    else {
      if ((*(int *)(pdVar20 + 1) == 4) && (iVar5 = FUN_006f7760(), iVar5 != 0)) {
        *pdVar20 = local_90;
        *(undefined4 *)(pdVar20 + 1) = 3;
        goto LAB_006fd153;
      }
LAB_006fd1e8:
      FUN_006f8b60();
    }
LAB_006fd1f0:
    *pdVar20 = *pdVar20 - *local_c4;
    *(undefined4 *)(pdVar20 + 1) = 3;
    puVar18 = local_cc + ((uVar17 >> 0xe) - 0x1fffe);
    goto switchD_006fc5f1_default;
  case 0x21:
    *(undefined4 *)(pdVar20 + 10) = *(undefined4 *)(pdVar20 + 4);
    *(undefined4 *)((int)pdVar20 + 0x54) = *(undefined4 *)((int)pdVar20 + 0x24);
    *(undefined4 *)(pdVar20 + 0xb) = *(undefined4 *)(pdVar20 + 5);
    *(undefined4 *)(pdVar20 + 8) = *(undefined4 *)(pdVar20 + 2);
    *(undefined4 *)((int)pdVar20 + 0x44) = *(undefined4 *)((int)pdVar20 + 0x14);
    *(undefined4 *)(pdVar20 + 9) = *(undefined4 *)(pdVar20 + 3);
    *(undefined4 *)(pdVar20 + 6) = *(undefined4 *)pdVar20;
    *(undefined4 *)((int)pdVar20 + 0x34) = *(undefined4 *)((int)pdVar20 + 4);
    *(undefined4 *)(pdVar20 + 7) = *(undefined4 *)(pdVar20 + 1);
    *(double **)(param_1 + 8) = pdVar20 + 0xc;
    *(uint **)(param_1 + 0x18) = puVar18;
    FUN_006fe550(param_1);
    local_c8 = *(int *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)(param_1 + 0x14) + 8);
    puVar8 = (undefined4 *)((uVar4 + 3) * 0x10 + local_c8);
    if (puVar8[2] != 0) {
      puVar8[-4] = *puVar8;
      puVar8[-3] = puVar8[1];
      puVar8[-2] = puVar8[2];
      puVar18 = local_cc + ((*puVar18 >> 0xe) - 0x1fffe);
    }
    local_cc = puVar18;
    puVar18 = local_cc + 1;
    goto switchD_006fc5f1_default;
  case 0x22:
    local_bc = uVar17 >> 0x17;
    uVar17 = uVar17 >> 0xe & 0x1ff;
    if (local_bc == 0) {
      local_bc = (*(int *)(param_1 + 8) - (int)pdVar20 >> 4) - 1;
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)(param_1 + 0x14) + 8);
    }
    if (uVar17 == 0) {
      uVar17 = *puVar18;
      puVar18 = local_cc + 2;
    }
    local_cc = puVar18;
    puVar18 = local_cc;
    if (*(int *)(pdVar20 + 1) == 5) {
      iVar5 = *(int *)pdVar20;
      local_c4 = (double *)(uVar17 * 0x32 + -0x32 + local_bc);
      if (*(int *)(iVar5 + 0x1c) < (int)local_c4) {
        FUN_006f9810();
      }
      if (0 < (int)local_bc) {
        pdVar20 = pdVar20 + local_bc * 2;
        do {
          puVar8 = (undefined4 *)FUN_006f9b70();
          if (puVar8 == &DAT_00c0bfc8) {
            local_50 = (double)(int)local_c4;
            local_48 = 3;
            puVar8 = (undefined4 *)FUN_006f9a60(param_1);
          }
          local_c4 = (double *)((int)local_c4 + -1);
          *puVar8 = *(undefined4 *)pdVar20;
          puVar8[1] = *(undefined4 *)((int)pdVar20 + 4);
          puVar8[2] = *(undefined4 *)(pdVar20 + 1);
          if (((3 < *(int *)(pdVar20 + 1)) && ((*(byte *)(*(int *)pdVar20 + 5) & 3) != 0)) &&
             ((*(byte *)(iVar5 + 5) & 4) != 0)) {
            iVar9 = *(int *)(param_1 + 0x10);
            *(byte *)(iVar5 + 5) = *(byte *)(iVar5 + 5) & 0xfb;
            *(undefined4 *)(iVar5 + 0x18) = *(undefined4 *)(iVar9 + 0x28);
            *(int *)(iVar9 + 0x28) = iVar5;
          }
          local_bc = local_bc - 1;
          pdVar20 = pdVar20 + -2;
        } while (0 < (int)local_bc);
      }
    }
    goto switchD_006fc5f1_default;
  case 0x23:
    FUN_006fd860();
    goto switchD_006fc5f1_default;
  case 0x24:
    iVar5 = *(int *)(*(int *)(*(int *)(iVar11 + 0x10) + 0x10) + (uVar17 >> 0xe) * 4);
    uVar17 = (uint)*(byte *)(iVar5 + 0x48);
    iVar9 = FUN_006fd730(uVar17,*(undefined4 *)(iVar11 + 0xc));
    *(int *)(iVar9 + 0x10) = iVar5;
    if (uVar17 != 0) {
      local_c4 = (double *)(iVar9 + 0x14);
      do {
        if (((byte)*puVar18 & 0x3f) == 4) {
          *(undefined4 *)local_c4 = *(undefined4 *)(iVar11 + 0x14 + (*puVar18 >> 0x17) * 4);
        }
        else {
          uVar10 = FUN_006fd7a0();
          *(undefined4 *)local_c4 = uVar10;
        }
        local_c4 = (double *)((int)local_c4 + 4);
        puVar18 = puVar18 + 1;
        uVar17 = uVar17 - 1;
      } while (uVar17 != 0);
    }
    *(int *)pdVar20 = iVar9;
    *(undefined4 *)(pdVar20 + 1) = 6;
    *(uint **)(param_1 + 0x18) = puVar18;
    if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    local_c8 = *(int *)(param_1 + 0xc);
    goto switchD_006fc5f1_default;
  case 0x25:
    piVar7 = *(int **)(param_1 + 0x14);
    iVar9 = (uVar17 >> 0x17) - 1;
    iVar19 = ((*piVar7 - piVar7[1] >> 4) - (uint)*(byte *)(*(int *)(iVar11 + 0x10) + 0x49)) + -1;
    if (iVar9 == -1) {
      *(uint **)(param_1 + 0x18) = puVar18;
      if (*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 8) <= iVar19 * 0x10) {
        FUN_006fdcb0();
      }
      local_c8 = *(int *)(param_1 + 0xc);
      pdVar20 = (double *)(iVar5 + local_c8);
      *(double **)(param_1 + 8) = pdVar20 + iVar19 * 2;
      iVar9 = iVar19;
    }
    iVar5 = 0;
    if (0 < iVar9) {
      iVar12 = iVar19 * -0x10;
      pdVar20 = pdVar20 + 1;
      do {
        if (iVar5 < iVar19) {
          iVar3 = *piVar7;
          *(undefined4 *)(pdVar20 + -1) = *(undefined4 *)(iVar3 + iVar12);
          *(undefined4 *)((int)pdVar20 + -4) = *(undefined4 *)(iVar3 + 4 + iVar12);
          *(undefined4 *)pdVar20 = *(undefined4 *)(iVar3 + 8 + iVar12);
        }
        else {
          *(undefined4 *)pdVar20 = 0;
        }
        iVar5 = iVar5 + 1;
        iVar12 = iVar12 + 0x10;
        pdVar20 = pdVar20 + 2;
      } while (iVar5 < iVar9);
    }
  default:
    goto switchD_006fc5f1_default;
  }
  *(uint **)(param_1 + 0x18) = puVar18;
  FUN_006fc390(param_1,pdVar20,pdVar16);
  local_c8 = *(int *)(param_1 + 0xc);
  goto switchD_006fc5f1_default;
switchD_006fc5f1_caseD_1e:
  if (uVar17 >> 0x17 != 0) {
    *(double **)(param_1 + 8) = pdVar20 + (uVar17 >> 0x17) * 2 + -2;
  }
  if (*(int *)(param_1 + 0x68) != 0) {
    FUN_006fd860();
  }
  *(uint **)(param_1 + 0x18) = puVar18;
  iVar11 = FUN_006fe4c0();
  param_2 = param_2 + -1;
  if (param_2 == 0) {
    return;
  }
  if (iVar11 != 0) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)(param_1 + 0x14) + 8);
  }
  goto LAB_006fc562;
}

