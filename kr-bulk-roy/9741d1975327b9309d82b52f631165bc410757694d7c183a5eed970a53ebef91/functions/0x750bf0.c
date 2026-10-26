
void FUN_00750bf0(int *param_1,undefined4 param_2)

{
  int iVar1;
  float fVar2;
  int *piVar3;
  float *in_EAX;
  int in_ECX;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((param_1[2] != *param_1 && -1 < param_1[2] - *param_1) &&
     (param_1[3] != param_1[1] && -1 < param_1[3] - param_1[1])) {
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x108))(*(int **)(in_ECX + 0x1c),0,2,&local_8);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x108))(*(int **)(in_ECX + 0x1c),0,3,&local_c);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x108))(*(int **)(in_ECX + 0x1c),0,1,&local_10);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x108))(*(int **)(in_ECX + 0x1c),0,5,&local_14);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x108))(*(int **)(in_ECX + 0x1c),0,6,&local_18);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x108))(*(int **)(in_ECX + 0x1c),0,4,&local_1c);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x10c))(*(int **)(in_ECX + 0x1c),0,2,0);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x10c))(*(int **)(in_ECX + 0x1c),0,1,2);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x10c))(*(int **)(in_ECX + 0x1c),0,5,0);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x10c))(*(int **)(in_ECX + 0x1c),0,4,2);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x104))(*(int **)(in_ECX + 0x1c),0,0);
    iVar1 = param_1[3];
    fVar2 = in_EAX[1];
    *(float *)(in_ECX + 0x14d4) = ((float)*param_1 + *in_EAX) - 0.5;
    *(float *)(in_ECX + 0x14d8) = ((float)iVar1 + fVar2) - 0.5;
    *(undefined4 *)(in_ECX + 0x14dc) = 0;
    iVar1 = param_1[3];
    fVar2 = in_EAX[1];
    *(float *)(in_ECX + 0x14e8) = ((float)param_1[2] + *in_EAX) - 0.5;
    *(float *)(in_ECX + 0x14ec) = ((float)iVar1 + fVar2) - 0.5;
    *(undefined4 *)(in_ECX + 0x14f0) = 0;
    iVar1 = param_1[1];
    fVar2 = in_EAX[1];
    *(float *)(in_ECX + 0x14fc) = ((float)*param_1 + *in_EAX) - 0.5;
    *(float *)(in_ECX + 0x1500) = ((float)iVar1 + fVar2) - 0.5;
    *(undefined4 *)(in_ECX + 0x1504) = 0;
    iVar1 = param_1[1];
    fVar2 = in_EAX[1];
    *(float *)(in_ECX + 0x1510) = ((float)param_1[2] + *in_EAX) - 0.5;
    *(float *)(in_ECX + 0x1514) = ((float)iVar1 + fVar2) - 0.5;
    *(undefined4 *)(in_ECX + 0x1518) = 0;
    *(undefined4 *)(in_ECX + 0x14e4) = param_2;
    *(undefined4 *)(in_ECX + 0x14f8) = param_2;
    *(undefined4 *)(in_ECX + 0x150c) = param_2;
    *(undefined4 *)(in_ECX + 0x1520) = param_2;
    FUN_007538e0((float *)(in_ECX + 0x14d4));
    piVar3 = *(int **)(in_ECX + 0x1c);
    (**(code **)(*piVar3 + 400))(piVar3,0,*(undefined4 *)(in_ECX + 0x1594),0,0x14);
    (**(code **)(*piVar3 + 0x164))(piVar3,0x44);
    (**(code **)(*piVar3 + 0x144))(piVar3,5,0,2);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x10c))(*(int **)(in_ECX + 0x1c),0,2,local_8);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x10c))(*(int **)(in_ECX + 0x1c),0,3,local_c);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x10c))(*(int **)(in_ECX + 0x1c),0,1,local_10);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x10c))(*(int **)(in_ECX + 0x1c),0,5,local_14);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x10c))(*(int **)(in_ECX + 0x1c),0,6,local_18);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x10c))(*(int **)(in_ECX + 0x1c),0,4,local_1c);
  }
  return;
}

