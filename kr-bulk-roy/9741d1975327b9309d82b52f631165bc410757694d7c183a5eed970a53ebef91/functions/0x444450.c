
undefined4 FUN_00444450(undefined4 param_1)

{
  int iVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  int in_ECX;
  float10 fVar8;
  float fVar9;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009398ae;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((*(int *)(in_ECX + 4) != 0) && (piVar3 = *(int **)(in_ECX + 0xc), piVar3 != (int *)0x0)) {
    iVar7 = piVar3[0x28];
    iVar1 = piVar3[0x29];
    fVar2 = (float)piVar3[0x2a];
    if ((piVar3[0x57] == 0) || (piVar3[0xdc] == 0)) {
      local_14 = 0.0;
    }
    else {
      fVar8 = (float10)FUN_007a7100(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      local_14 = (float)fVar8;
    }
    iVar4 = *(int *)(in_ECX + 0xb4);
    *(int *)(iVar4 + 0xc) = iVar7;
    *(int *)(iVar4 + 0x10) = iVar1;
    *(float *)(iVar4 + 0x14) = local_14 + 2.0 + fVar2;
    fVar2 = (float)piVar3[0x2d];
    fVar9 = fVar2;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 0;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_8 = 0xffffffff;
    }
    piVar5 = *(int **)(in_ECX + 0xb4);
    fVar2 = DAT_00fb90bc * fVar2;
    piVar5[1] = (int)fVar2;
    iVar7 = *piVar5;
    if ((iVar7 != 0) && (*(float *)(iVar7 + 0x10) = fVar2, fVar9 = fVar2, *(int *)(iVar7 + 4) != 0))
    {
      FUN_0077ef50(fVar2,fVar2,fVar2);
    }
    FUN_0079c650(param_1);
    if (*(int *)(in_ECX + 0xb8) != 0) {
      iVar7 = **(int **)(in_ECX + 0xb8);
      puVar6 = (undefined4 *)(**(code **)(*piVar3 + 0x4c))();
      (**(code **)(iVar7 + 0x10))(*puVar6,puVar6[1],puVar6[2]);
      iVar7 = **(int **)(in_ECX + 0xb8);
      local_14 = (float)CONCAT31((int3)((uint)fVar2 >> 8),(char)piVar3[0xe9]);
      FUN_00444a90(local_14);
      (**(code **)(iVar7 + 0xc))(fVar9);
      fVar2 = (float)piVar3[0x2d];
      iVar7 = FUN_00444ad0();
      (**(code **)(**(int **)(in_ECX + 0xb8) + 8))(*(float *)(iVar7 + 0x6c) * fVar2);
      FUN_0079cbd0();
      (**(code **)(**(int **)(in_ECX + 0xb8) + 4))(param_1);
    }
  }
  ExceptionList = local_10;
  return 0;
}

