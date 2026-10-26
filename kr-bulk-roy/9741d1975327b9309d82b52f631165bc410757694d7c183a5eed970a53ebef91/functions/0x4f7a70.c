
void FUN_004f7a70(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  uint *in_EDX;
  undefined4 *puVar4;
  undefined1 local_f4 [4];
  undefined1 local_f0;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined2 local_d4;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined1 local_b8;
  undefined4 local_a8;
  undefined4 local_a4;
  uint local_88;
  undefined1 local_84 [104];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00917513;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)local_f4;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffff00;
  ExceptionList = &local_14;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar4[1] + 0x75) == '\0') {
    puVar2 = (undefined4 *)puVar4[1];
    do {
      if ((uint)puVar2[3] < *in_EDX) {
        puVar3 = (undefined4 *)puVar2[2];
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
        puVar4 = puVar2;
      }
      puVar2 = puVar3;
    } while (*(char *)((int)puVar3 + 0x75) == '\0');
  }
  if ((puVar4 == *(undefined4 **)(in_ECX + 4)) || (*in_EDX < (uint)puVar4[3])) {
    local_dc = 0xf;
    local_e0 = 0;
    local_f0 = 0;
    local_c0 = 7;
    local_c4 = 0;
    local_d4 = 0;
    local_a4 = 0xf;
    local_a8 = 0;
    local_b8 = 0;
    local_c = 0;
    local_88 = *in_EDX;
    FUN_004f81f0(local_84);
    local_c = CONCAT31(local_c._1_3_,1);
    FUN_004f9c20(&local_88);
    FUN_004f8d70(in_ECX,puVar4);
    FUN_004f52b0(uVar1);
    FUN_004f52b0();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)local_f4);
  return;
}

