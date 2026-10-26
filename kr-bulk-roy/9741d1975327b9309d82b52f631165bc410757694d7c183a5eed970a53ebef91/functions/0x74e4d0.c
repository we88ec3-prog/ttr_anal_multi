
void FUN_0074e4d0(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 in_EAX;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 in_ECX;
  
  *(int **)(param_1 + 0x1c) = param_2;
  *(undefined4 *)(param_1 + 0xa0) = in_EAX;
  *(undefined4 *)(param_1 + 0xa4) = in_ECX;
  D3DXCreateSprite(param_2,param_1 + 0x18);
  D3DXMatrixOrthoLH(param_1 + 0x60,(float)*(int *)(param_1 + 0xa0),(float)*(int *)(param_1 + 0xa4),0
                    ,0x3f800000);
  FUN_00753020(0,0,*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xa4));
  iVar2 = (**(code **)(*param_2 + 0x5c))
                    (param_2,*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xa4),1,1,
                     0x15,0,(undefined4 *)(param_1 + 0x10),0);
  if (-1 < iVar2) {
    piVar1 = *(int **)(param_1 + 0x10);
    (**(code **)(*piVar1 + 0x48))(piVar1,0,param_1 + 0x14);
  }
  uVar3 = FUN_008fed10();
  uVar4 = FUN_008fed10();
  iVar2 = (**(code **)(*param_2 + 0x5c))
                    (param_2,uVar4,uVar3,1,1,0x15,0,(undefined4 *)(param_1 + 8),0);
  if (-1 < iVar2) {
    piVar1 = *(int **)(param_1 + 8);
    (**(code **)(*piVar1 + 0x48))(piVar1,0,param_1 + 0xc);
  }
  (**(code **)(*param_2 + 0xec))(param_2,1,param_1 + 0x14b4);
  (**(code **)(*param_2 + 0xec))(param_2,1,(int *)(param_1 + 0x14b8));
  piVar1 = *(int **)(param_1 + 0x14b4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))(piVar1);
  }
  (**(code **)(**(int **)(param_1 + 0x1c) + 0xe4))(*(int **)(param_1 + 0x1c),0x30,0);
  (**(code **)(**(int **)(param_1 + 0x1c) + 0xe4))(*(int **)(param_1 + 0x1c),0x1c,0);
  (**(code **)(**(int **)(param_1 + 0x1c) + 0xe4))(*(int **)(param_1 + 0x1c),0x89,0);
  (**(code **)(**(int **)(param_1 + 0x1c) + 0xe4))(*(int **)(param_1 + 0x1c),0x1b,1);
  (**(code **)(**(int **)(param_1 + 0x1c) + 0xe4))(*(int **)(param_1 + 0x1c),0x13,2);
  (**(code **)(**(int **)(param_1 + 0x1c) + 0xe4))(*(int **)(param_1 + 0x1c),0x14,6);
  (**(code **)(**(int **)(param_1 + 0x1c) + 0xe4))(*(int **)(param_1 + 0x1c),0x16,1);
  (**(code **)(**(int **)(param_1 + 0x1c) + 0xe4))(*(int **)(param_1 + 0x1c),7,0);
  (**(code **)(**(int **)(param_1 + 0x1c) + 0xe4))(*(int **)(param_1 + 0x1c),0xe,0);
  (**(code **)(**(int **)(param_1 + 0x1c) + 0xe4))(*(int **)(param_1 + 0x1c),0xf,0);
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x114))(*(int **)(param_1 + 0x1c),0,1,3);
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x114))(*(int **)(param_1 + 0x1c),0,2,3);
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x114))(*(int **)(param_1 + 0x1c),0,5,2);
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x114))(*(int **)(param_1 + 0x1c),0,6,2);
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x114))(*(int **)(param_1 + 0x1c),0,7,0);
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x10c))(*(int **)(param_1 + 0x1c),0,2,2);
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x10c))(*(int **)(param_1 + 0x1c),0,3,0);
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x10c))(*(int **)(param_1 + 0x1c),0,1,4);
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x10c))(*(int **)(param_1 + 0x1c),0,5,2);
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x10c))(*(int **)(param_1 + 0x1c),0,6,0);
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x10c))(*(int **)(param_1 + 0x1c),0,4,4);
  piVar1 = *(int **)(param_1 + 0x14b8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x14b4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x14))(piVar1);
  }
  (**(code **)(*param_2 + 0x68))(param_2,0x50,0x208,0x44,0,param_1 + 0x1594,0);
  (**(code **)(*param_2 + 0x68))(param_2,0x70,0x208,0x144,0,param_1 + 0x1598,0);
  (**(code **)(*param_2 + 0x68))(param_2,0x15000,0x208,0x144,0,param_1 + 0x165a0,0);
  piVar1 = *(int **)(param_1 + 0x13c4);
  if (piVar1 != (int *)0x0) {
    uVar3 = FUN_008fed10();
    uVar4 = FUN_008fed10();
    (**(code **)(*piVar1 + 0xbc))(0,0,uVar3,uVar4);
    FUN_00746bd0();
    (**(code **)(**(int **)(param_1 + 0x13c4) + 200))();
  }
  return;
}

