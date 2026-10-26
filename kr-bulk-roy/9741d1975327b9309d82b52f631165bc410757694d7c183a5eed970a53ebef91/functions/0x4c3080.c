
void FUN_004c3080(int param_1)

{
  undefined2 *in_ECX;
  undefined2 *puVar1;
  undefined2 *puVar2;
  int local_2c;
  uint local_28;
  undefined4 local_24;
  undefined1 local_20 [20];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_2c;
  FUN_004c4240();
  if (param_1 != 0) {
    local_2c = param_1;
    do {
      puVar1 = (undefined2 *)((int)in_ECX + 3);
      local_24 = FUN_00507510();
      local_28 = 0;
      puVar2 = puVar1;
      if (*(char *)(in_ECX + 1) != '\0') {
        do {
          puVar1 = puVar2 + 5;
          FUN_004c4330("%d.%d.%d.%d",*(undefined1 *)(puVar2 + 2),*(undefined1 *)((int)puVar2 + 5),
                       *(undefined1 *)(puVar2 + 3),*(undefined1 *)((int)puVar2 + 7));
          if (*(char *)(puVar2 + 4) != '\0') {
            FUN_00507610(DAT_00fe1b54,local_24,*puVar2,local_20);
          }
          local_28 = local_28 + 1;
          puVar2 = puVar1;
        } while (local_28 < *(byte *)(in_ECX + 1));
      }
      local_2c = local_2c + -1;
      in_ECX = puVar1;
    } while (local_2c != 0);
  }
  FUN_0058aad0(0xf4243);
  __security_check_cookie(local_c ^ (uint)&local_2c);
  return;
}

