
void FUN_00752bb0(void)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  int in_ECX;
  void *local_14;
  float local_10;
  float local_c;
  void *local_8;
  
  local_c = *(float *)(in_ECX + 0x13bc);
  local_8 = (void *)local_c;
  local_10 = (float)FUN_008fed10();
  local_14 = *(void **)(in_ECX + 0x13c0);
  local_8 = local_14;
  local_8 = (void *)FUN_008fed10();
  fVar2 = (float)(int)local_c;
  local_c = (float)(int)local_8 - 0.5;
  *(float *)(in_ECX + 0x1524) = fVar2 - 0.5;
  *(float *)(in_ECX + 0x1528) = local_c;
  *(undefined4 *)(in_ECX + 0x152c) = 0;
  local_10 = (float)(int)local_10 - 0.5;
  *(float *)(in_ECX + 0x1540) = local_10;
  *(float *)(in_ECX + 0x1544) = local_c;
  *(undefined4 *)(in_ECX + 0x1548) = 0;
  local_14 = (void *)((float)(int)local_14 - 0.5);
  *(float *)(in_ECX + 0x155c) = fVar2 - 0.5;
  *(void **)(in_ECX + 0x1560) = local_14;
  *(undefined4 *)(in_ECX + 0x1564) = 0;
  *(float *)(in_ECX + 0x1578) = local_10;
  *(void **)(in_ECX + 0x157c) = local_14;
  *(undefined4 *)(in_ECX + 0x1580) = 0;
  *(undefined4 *)(in_ECX + 0x1538) = 0;
  *(undefined4 *)(in_ECX + 0x153c) = 0x3f800000;
  *(undefined4 *)(in_ECX + 0x1554) = 0x3f800000;
  *(undefined4 *)(in_ECX + 0x1558) = 0x3f800000;
  *(undefined4 *)(in_ECX + 0x158c) = 0x3f800000;
  *(undefined4 *)(in_ECX + 0x1570) = 0;
  *(undefined4 *)(in_ECX + 0x1574) = 0;
  *(undefined4 *)(in_ECX + 0x1590) = 0;
  (**(code **)(**(int **)(in_ECX + 0x1c) + 0x114))(*(int **)(in_ECX + 0x1c),0,5,1);
  (**(code **)(**(int **)(in_ECX + 0x1c) + 0x114))(*(int **)(in_ECX + 0x1c),0,6,1);
  (**(code **)(**(int **)(in_ECX + 0x1c) + 0x114))(*(int **)(in_ECX + 0x1c),0,7,0);
  (**(code **)(**(int **)(in_ECX + 0x1c) + 0x104))
            (*(int **)(in_ECX + 0x1c),0,*(undefined4 *)(in_ECX + 0x10));
  iVar3 = (**(code **)(**(int **)(in_ECX + 0x1598) + 0x2c))
                    (*(int **)(in_ECX + 0x1598),0,0x70,&local_14,0x2000);
  if (-1 < iVar3) {
    FID_conflict__memcpy(local_14,(float *)(in_ECX + 0x1524),0x70);
    (**(code **)(**(int **)(in_ECX + 0x1598) + 0x30))(*(int **)(in_ECX + 0x1598));
  }
  piVar1 = *(int **)(in_ECX + 0x1c);
  (**(code **)(*piVar1 + 400))(piVar1,0,*(undefined4 *)(in_ECX + 0x1598),0,0x1c);
  (**(code **)(*piVar1 + 0x164))(piVar1,0x144);
  (**(code **)(*piVar1 + 0x144))(piVar1,5,0,2);
  (**(code **)(**(int **)(in_ECX + 0x1c) + 0x104))(*(int **)(in_ECX + 0x1c),0,0);
  (**(code **)(**(int **)(in_ECX + 0x1c) + 0x114))(*(int **)(in_ECX + 0x1c),0,5,2);
  (**(code **)(**(int **)(in_ECX + 0x1c) + 0x114))(*(int **)(in_ECX + 0x1c),0,6,2);
  (**(code **)(**(int **)(in_ECX + 0x1c) + 0x114))(*(int **)(in_ECX + 0x1c),0,7,0);
  return;
}

