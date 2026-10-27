
void FUN_008330e0(undefined4 *param_1,undefined4 *param_2,int *param_3,int param_4)

{
  float fVar1;
  void *pvVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090466b;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = *param_3;
  param_1[3] = param_3[1];
  iVar6 = (*(int **)(param_4 + 0x18))[1];
  fVar1 = (*(float **)(param_4 + 0x1c))[1];
  param_1[4] = (float)**(int **)(param_4 + 0x18) / **(float **)(param_4 + 0x1c);
  pvVar2 = (void *)param_1[6];
  param_1[5] = (float)iVar6 / fVar1;
  if (pvVar2 != (void *)0x0) {
    _eh_vector_destructor_iterator_(pvVar2,0x10,*(int *)((int)pvVar2 + -4),FUN_00837b60);
    FUN_00891d3d((int)pvVar2 + -4);
    param_1[6] = 0;
  }
  uVar8 = param_3[1] * *param_3;
  uVar5 = -(uint)((int)((ulonglong)uVar8 * 0x10 >> 0x20) != 0) | (uint)((ulonglong)uVar8 * 0x10);
  puVar4 = (uint *)FUN_0087dc3d(-(uint)(0xfffffffb < uVar5) | uVar5 + 4,uVar3);
  local_8 = 0;
  if (puVar4 == (uint *)0x0) {
    puVar4 = (uint *)0x0;
  }
  else {
    *puVar4 = uVar8;
    puVar4 = puVar4 + 1;
    _eh_vector_constructor_iterator_
              (puVar4,0x10,uVar8,(_func_void_void_ptr *)&LAB_00689330,FUN_00837b60);
  }
  local_8 = 0xffffffff;
  param_1[6] = puVar4;
  local_14 = 0;
  if (0 < param_3[1]) {
    iVar6 = *param_3;
    do {
      iVar7 = 0;
      if (0 < iVar6) {
        do {
          FUN_00837be0((iVar6 * local_14 + iVar7) * 0x10 + param_1[6],param_4);
          iVar6 = *param_3;
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar6);
      }
      local_14 = local_14 + 1;
    } while (local_14 < param_3[1]);
  }
  ExceptionList = local_10;
  return;
}

