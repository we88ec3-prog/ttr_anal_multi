
undefined4 FUN_0083d7f0(float param_1,float param_2,float param_3,float param_4)

{
  int *piVar1;
  int in_EAX;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_10;
  
  piVar1 = *(int **)(in_EAX + 0xec);
  if (piVar1 != (int *)0x0) {
    local_10 = (uint)(longlong)ROUND(param_1 * 255.0);
    uVar4 = local_10 & 0xff;
    local_10 = (uint)(longlong)ROUND(param_4 * 255.0);
    uVar2 = local_10 << 8;
    local_10 = (uint)(longlong)ROUND(param_2 * 255.0);
    uVar3 = local_10 & 0xff;
    local_10 = (uint)(longlong)ROUND(param_3 * 255.0);
    (**(code **)(*piVar1 + 0xac))
              (piVar1,0,0,1,((uVar4 | uVar2) << 8 | uVar3) << 8 | local_10 & 0xff,0,1);
    return 1;
  }
  return 0;
}

