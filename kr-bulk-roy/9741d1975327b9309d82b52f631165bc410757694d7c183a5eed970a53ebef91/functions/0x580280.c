
void FUN_00580280(void)

{
  double dVar1;
  int *in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 in_FPUControlWord;
  int local_20;
  int *local_1c;
  int *local_18;
  undefined8 local_14;
  int local_c;
  undefined4 local_8;
  
  FUN_007343d0(0x400);
  local_18 = (int *)(**(code **)(*in_EAX + 0x10))();
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 0x4c))(local_18,0,&local_20,0,0x2000);
    local_c = (int)((local_20 >> 0x1f & 3U) + local_20) >> 2;
    iVar5 = 0x60;
    iVar4 = 0;
    do {
      iVar3 = 0;
      if (0 < local_c) {
        do {
          if (iVar3 < iVar5) {
            *local_1c = 0;
          }
          else {
            iVar2 = iVar3 - iVar5;
            local_8 = iVar4 + 0x20;
            local_14 = CONCAT44(iVar2,(int)local_14);
            if (iVar2 < local_8) {
              dVar1 = (double)local_8;
              local_8 = CONCAT22(in_FPUControlWord,(undefined2)local_8);
              local_14 = (longlong)ROUND((255.0 / dVar1) * (double)iVar2);
              *local_1c = (int)local_14 << 0x18;
            }
            else {
              *local_1c = -0x1000000;
            }
          }
          iVar3 = iVar3 + 1;
          local_1c = local_1c + 1;
        } while (iVar3 < local_c);
      }
      iVar4 = iVar4 + 2;
      iVar5 = iVar5 + -2;
    } while (iVar4 < 0x60);
    iVar4 = 0x10;
    do {
      iVar5 = local_c;
      if (0 < local_c) {
        do {
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        *local_1c = 0;
      }
      local_1c = local_1c + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    (**(code **)(*local_18 + 0x50))(local_18,0);
  }
  return;
}

