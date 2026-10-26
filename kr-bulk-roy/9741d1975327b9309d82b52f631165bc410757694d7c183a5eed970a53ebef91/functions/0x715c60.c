
void FUN_00715c60(int *param_1,undefined4 *param_2)

{
  code *pcVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined8 local_12c;
  int local_124;
  uint local_120;
  int *local_11c;
  undefined4 *local_118;
  char local_114 [256];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090f31e;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_118 = param_2;
  local_11c = (int *)0x0;
  if (param_1 != (int *)0x0) {
    (**(code **)*param_1)(&local_120,2,local_14);
    uVar6 = local_120 & 0xffff;
    if (uVar6 < 0x100) {
      (**(code **)*param_1)(local_114,uVar6);
      pcVar1 = *(code **)(*param_1 + 4);
      local_114[uVar6] = '\0';
      cVar2 = (*pcVar1)();
      if (cVar2 == '\x01') {
        (**(code **)*param_1)(&local_120,4);
        (**(code **)*param_1)(&local_12c,8);
        local_11c = (int *)FUN_00891268(0x138);
        iVar5 = 0;
        local_8 = 0;
        if (local_11c == (int *)0x0) {
          piVar3 = (int *)0x0;
        }
        else {
          piVar3 = (int *)FUN_00717840(local_11c);
        }
        local_8 = 0xffffffff;
        local_11c = piVar3;
        _strcpy_s((char *)(piVar3 + 3),0x100,local_114);
        *(undefined8 *)(piVar3 + 0x44) = local_12c;
        if (0 < (int)local_120) {
          do {
            iVar4 = FUN_00715c60(param_1,local_118);
            if (iVar4 == 0) {
              *local_118 = 1;
              break;
            }
            (**(code **)(*piVar3 + 0x30))(iVar4);
            iVar5 = iVar5 + 1;
          } while (iVar5 < (int)local_120);
        }
      }
      else if (cVar2 == '\0') {
        iVar5 = FUN_00891268(0x128);
        if (iVar5 == 0) {
          piVar3 = (int *)0x0;
        }
        else {
          piVar3 = (int *)FUN_00717a00();
        }
        local_11c = piVar3;
        _strcpy_s((char *)(piVar3 + 3),0x100,local_114);
        (**(code **)*param_1)(&local_124,4);
        piVar3[0x48] = local_124;
        (**(code **)*param_1)(&local_118,4);
        piVar3[0x47] = (int)local_118;
        (**(code **)*param_1)(&local_12c,8);
        *(undefined8 *)(piVar3 + 0x44) = local_12c;
      }
      else {
        FID_conflict__wprintf("ERROR");
      }
    }
    else {
      *param_2 = 1;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

