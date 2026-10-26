
void FUN_00775960(float param_1,float param_2)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  void *local_8;
  
  piVar1 = *(int **)(in_EAX + 0x74);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x108))(piVar1,0,2,&local_c);
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x108))(*(int **)(in_EAX + 0x74),0,3,&local_10);
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x108))(*(int **)(in_EAX + 0x74),0,1,&local_14);
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x108))(*(int **)(in_EAX + 0x74),0,5,&local_18);
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x108))(*(int **)(in_EAX + 0x74),0,6,&local_1c);
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x108))(*(int **)(in_EAX + 0x74),0,4,&local_20);
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x110))(*(int **)(in_EAX + 0x74),0,1,&local_24);
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x110))(*(int **)(in_EAX + 0x74),0,2,&local_28);
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x10c))(*(int **)(in_EAX + 0x74),0,2,0);
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x10c))(*(int **)(in_EAX + 0x74),0,1,2);
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x10c))(*(int **)(in_EAX + 0x74),0,5,2);
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x10c))(*(int **)(in_EAX + 0x74),0,4,2);
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x114))(*(int **)(in_EAX + 0x74),0,1,1);
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x114))(*(int **)(in_EAX + 0x74),0,2,1);
    *(undefined4 *)(in_EAX + 0x14) = 0xff7d0000;
    *(undefined4 *)(in_EAX + 0x30) = 0xff7d0000;
    *(float *)(in_EAX + 4) = param_1 * (*(float *)(in_EAX + 4) + 0.0) - 0.5;
    *(float *)(in_EAX + 8) = param_2 * (*(float *)(in_EAX + 8) + 0.0) - 0.5;
    *(float *)(in_EAX + 0x20) = (*(float *)(in_EAX + 0x20) + 0.0) * param_1 - 0.5;
    *(float *)(in_EAX + 0x24) = (*(float *)(in_EAX + 0x24) + 0.0) * param_2 - 0.5;
    *(float *)(in_EAX + 0x3c) = (*(float *)(in_EAX + 0x3c) + 0.0) * param_1 - 0.5;
    *(float *)(in_EAX + 0x40) = (*(float *)(in_EAX + 0x40) + 0.0) * param_2 - 0.5;
    *(undefined4 *)(in_EAX + 0x4c) = 0xff7d0000;
    *(undefined4 *)(in_EAX + 0x68) = 0xff7d0000;
    *(float *)(in_EAX + 0x58) = (*(float *)(in_EAX + 0x58) + 0.0) * param_1 - 0.5;
    *(float *)(in_EAX + 0x5c) = param_2 * (*(float *)(in_EAX + 0x5c) + 0.0) - 0.5;
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x104))
              (*(int **)(in_EAX + 0x74),0,*(undefined4 *)(in_EAX + 0x7c));
    iVar2 = (**(code **)(**(int **)(in_EAX + 0x78) + 0x2c))
                      (*(int **)(in_EAX + 0x78),0,0x70,&local_8,0);
    if (-1 < iVar2) {
      FID_conflict__memcpy(local_8,(float *)(in_EAX + 4),0x70);
      (**(code **)(**(int **)(in_EAX + 0x78) + 0x30))(*(int **)(in_EAX + 0x78));
    }
    piVar1 = *(int **)(in_EAX + 0x74);
    (**(code **)(*piVar1 + 400))(piVar1,0,*(undefined4 *)(in_EAX + 0x78),0,0x1c);
    (**(code **)(*piVar1 + 0x164))(piVar1,0x144);
    (**(code **)(*piVar1 + 0x144))(piVar1,5,0,2);
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x104))(*(int **)(in_EAX + 0x74),0,0);
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x10c))(*(int **)(in_EAX + 0x74),0,2,local_c);
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x10c))(*(int **)(in_EAX + 0x74),0,3,local_10);
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x10c))(*(int **)(in_EAX + 0x74),0,1,local_14);
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x10c))(*(int **)(in_EAX + 0x74),0,5,local_18);
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x10c))(*(int **)(in_EAX + 0x74),0,6,local_1c);
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x10c))(*(int **)(in_EAX + 0x74),0,4,local_20);
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x114))(*(int **)(in_EAX + 0x74),0,1,local_24);
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x114))(*(int **)(in_EAX + 0x74),0,2,local_28);
  }
  return;
}

