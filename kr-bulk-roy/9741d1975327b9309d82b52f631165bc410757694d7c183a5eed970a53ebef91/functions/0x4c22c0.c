
/* WARNING: Removing unreachable block (ram,0x004c23c1) */

void ** FUN_004c22c0(int param_1,int param_2)

{
  char cVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  void **ppvVar12;
  uint in_ECX;
  undefined2 *puVar13;
  int iVar14;
  undefined4 *puVar15;
  uint uVar16;
  undefined2 *puVar17;
  uint local_34;
  float local_30;
  void **local_2c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00939679;
  local_14 = ExceptionList;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  if (in_ECX < 2) {
    local_34 = 0;
    ppvVar12 = ExceptionList;
  }
  else {
    ppvVar12 = (void **)((in_ECX - 2) * 0x2f684bdb);
    local_34 = (in_ECX - 2) / 0x1b;
  }
  if (*(int *)(param_1 + 0xbd70) == 2) {
    fVar2 = (*(float *)(param_1 + 0xbd68) - *(float *)(param_1 + 0xbd60)) * 0.11111111;
    fVar3 = (*(float *)(param_1 + 0xbd6c) - *(float *)(param_1 + 0xbd64)) * 0.11111111;
    uVar16 = 0;
    local_30 = (*(float *)(param_1 + 0xbd60) + *(float *)(param_1 + 0xbd68)) * 0.5 -
               fVar2 * (float)local_34 * 0.5;
    ppvVar12 = (void **)((*(float *)(param_1 + 0xbd64) + *(float *)(param_1 + 0xbd6c)) * 0.5 -
                        fVar3 * (float)local_34 * 0.5);
    local_2c = ppvVar12;
    if (3 < local_34) {
      iVar14 = (local_34 - 4 >> 2) + 1;
      uVar16 = iVar14 * 4;
      do {
        iVar14 = iVar14 + -1;
        uVar8 = (uint)DAT_00000000;
        *(float *)(&DAT_00fba950 + uVar8 * 0x28) = local_30;
        *(void ***)(&DAT_00fba954 + uVar8 * 0x28) = local_2c;
        uVar8 = (uint)DAT_00000000;
        fVar5 = local_30 + fVar2 + fVar2;
        *(float *)(&DAT_00fba950 + uVar8 * 0x28) = local_30 + fVar2;
        *(float *)(&DAT_00fba954 + uVar8 * 0x28) = (float)local_2c + fVar3;
        uVar8 = (uint)DAT_00000000;
        fVar4 = (float)local_2c + fVar3 + fVar3;
        *(float *)(&DAT_00fba950 + uVar8 * 0x28) = fVar5;
        fVar5 = fVar5 + fVar2;
        *(float *)(&DAT_00fba954 + uVar8 * 0x28) = fVar4;
        uVar8 = (uint)DAT_00000000;
        fVar4 = fVar4 + fVar3;
        ppvVar12 = (void **)(uVar8 * 5);
        *(float *)(&DAT_00fba950 + uVar8 * 0x28) = fVar5;
        *(float *)(&DAT_00fba954 + uVar8 * 0x28) = fVar4;
        local_30 = fVar5 + fVar2;
        local_2c = (void **)(fVar4 + fVar3);
      } while (iVar14 != 0);
    }
    if (uVar16 < local_34) {
      iVar14 = local_34 - uVar16;
      do {
        iVar14 = iVar14 + -1;
        uVar16 = (uint)DAT_00000000;
        ppvVar12 = (void **)(uVar16 * 5);
        *(float *)(&DAT_00fba950 + uVar16 * 0x28) = local_30;
        *(void ***)(&DAT_00fba954 + uVar16 * 0x28) = local_2c;
        local_30 = local_30 + fVar2;
        local_2c = (void **)((float)local_2c + fVar3);
      } while (iVar14 != 0);
    }
  }
  if (local_34 != 0) {
    puVar17 = (undefined2 *)(param_2 + 10);
    do {
      iVar14 = FUN_00891268(0x420,uVar7);
      local_c = 0;
      if (iVar14 == 0) {
        piVar9 = (int *)0x0;
      }
      else {
        piVar9 = (int *)FUN_004c7070(iVar14);
      }
      local_c = 0xffffffff;
      *(ushort *)(piVar9 + 1) = (ushort)*(byte *)(puVar17 + -4) * 1000;
      puVar13 = (undefined2 *)(uint)*(byte *)(puVar17 + -4);
      (**(code **)(*piVar9 + 0x3c))();
      FUN_004c7df0(piVar9,1);
      if ((piVar9[0x57] != 0) && (piVar9[0xdc] != 0)) {
        FUN_007a7240(piVar9[0x57],*puVar17,*(undefined1 *)((int)puVar17 + -5),0);
      }
      if ((piVar9[0x57] != 0) && (piVar9[0xdc] != 0)) {
        FUN_007a7240(piVar9[0x57],puVar17[1],0,0);
      }
      if ((piVar9[0x57] != 0) && (piVar9[0xdc] != 0)) {
        FUN_007a7240(piVar9[0x57],puVar17[-2],*(undefined1 *)(puVar17 + -3),
                     *(undefined1 *)((int)puVar17 + -7));
      }
      if ((piVar9[0x57] != 0) && (piVar9[0xdc] != 0)) {
        FUN_007a7240(piVar9[0x57],puVar17[-1],0,0);
      }
      if ((piVar9[0x57] != 0) && (piVar9[0xdc] != 0)) {
        FUN_007a7240(piVar9[0x57],puVar17[3],0,0);
      }
      if ((piVar9[0x57] != 0) && (piVar9[0xdc] != 0)) {
        FUN_007a7240(piVar9[0x57],puVar17[4],0,0);
      }
      if ((piVar9[0x57] != 0) && (piVar9[0xdc] != 0)) {
        FUN_007a7240(piVar9[0x57],puVar17[5],0,0);
      }
      if ((piVar9[0x57] != 0) && (piVar9[0xdc] != 0)) {
        FUN_007a7240(piVar9[0x57],puVar17[6],0,0);
      }
      if ((piVar9[0x57] != 0) && (piVar9[0xdc] != 0)) {
        FUN_007a7240(piVar9[0x57],puVar17[7],0,0);
      }
      if ((piVar9[0x57] != 0) && (piVar9[0xdc] != 0)) {
        FUN_007a7240(piVar9[0x57],puVar17[2],0,0);
      }
      if ((piVar9[0x57] != 0) && (piVar9[0xdc] != 0)) {
        FUN_007a7240(piVar9[0x57],puVar17[8],*(undefined1 *)(puVar17 + 9),0);
      }
      (**(code **)(*piVar9 + 0x44))(&DAT_00fba950 + (uint)*(byte *)(puVar17 + -4) * 0x28,1);
      (**(code **)(*piVar9 + 0x58))((&DAT_00fba958)[(uint)*(byte *)(puVar17 + -4) * 0x28]);
      (**(code **)(*piVar9 + 0x5c))
                (*(undefined4 *)(&DAT_00fba95c + (uint)*(byte *)(puVar17 + -4) * 0x28));
      piVar9[0x107] = 0;
      if (piVar9[0xda] != 0) {
        *(undefined4 *)(piVar9[0xda] + 0x24) = 0;
      }
      if ((DAT_00fab22c & 1) == 0) {
        DAT_00fab22c = DAT_00fab22c | 1;
        FUN_004dec90();
        _atexit((_func_4879 *)&LAB_00bcce30);
      }
      uVar16 = (uint)*(ushort *)(piVar9 + 1);
      cVar1 = *(char *)((int)DAT_00fab13c[1] + 0x15);
      puVar10 = (undefined4 *)DAT_00fab13c[1];
      puVar6 = DAT_00fab13c;
      while (puVar15 = puVar10, cVar1 == '\0') {
        if ((uint)puVar15[3] < uVar16) {
          puVar10 = (undefined4 *)puVar15[2];
          puVar15 = puVar6;
        }
        else {
          puVar10 = (undefined4 *)*puVar15;
        }
        cVar1 = *(char *)((int)puVar10 + 0x15);
        puVar6 = puVar15;
      }
      if ((puVar6 == DAT_00fab13c) || (uVar16 < (uint)puVar6[3])) {
        uVar11 = FUN_0057ef20();
        puVar17 = puVar13;
        FUN_0082f200(&DAT_00fab138,uVar11);
      }
      else {
        FUN_006edb60(&DAT_00c0cef0,uVar16);
      }
      (**(code **)(piVar9[0x3c] + 8))(0x14);
      if (*(int *)(&DAT_00fba974 + (uint)*(byte *)(puVar17 + -4) * 0x28) == 0) {
        uVar11 = 1;
      }
      else {
        uVar11 = 0xf;
      }
      ppvVar12 = (void **)(**(code **)(*piVar9 + 0x68))(uVar11,0x3f800000);
      puVar17 = (undefined2 *)((int)puVar17 + 0x1b);
      local_34 = local_34 - 1;
    } while (local_34 != 0);
  }
  ExceptionList = local_14;
  return ppvVar12;
}

