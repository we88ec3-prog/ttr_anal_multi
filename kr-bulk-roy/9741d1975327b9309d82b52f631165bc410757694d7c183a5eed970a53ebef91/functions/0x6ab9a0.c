
void FUN_006ab9a0(uint *param_1)

{
  uint in_ECX;
  int iVar1;
  int in_EDX;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint local_40;
  undefined4 local_3c;
  wchar_t local_38 [21];
  undefined4 local_d;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  switch(*(undefined1 *)(in_EDX + 2)) {
  case 1:
    break;
  case 2:
    param_1 = param_1 + 4;
    break;
  case 3:
    param_1 = param_1 + 0xc;
    break;
  case 4:
    param_1 = param_1 + 8;
    break;
  default:
    goto switchD_006ab9c8_default;
  }
  if (param_1 != (uint *)0x0) {
    FUN_006abbc0(param_1,&local_40,*param_1,param_1[1]);
    if (in_ECX < 3) {
      uVar2 = 0;
    }
    else {
      uVar2 = (in_ECX - 3) / 0x33;
    }
    if (uVar2 != 0) {
      puVar3 = (undefined4 *)(in_EDX + 0x32);
      local_40 = uVar2;
      do {
        local_3c = *(undefined4 *)((int)puVar3 + -0x2f);
        _wcscpy_s(local_38,0x15,(wchar_t *)((int)puVar3 + -0x2b));
        puVar5 = (undefined4 *)param_1[1];
        local_d = *puVar3;
        if ((&local_3c < puVar5) && (puVar4 = (undefined4 *)*param_1, puVar4 <= &local_3c)) {
          if (puVar5 == (undefined4 *)param_1[2]) {
            FUN_006abc10();
          }
          puVar5 = (undefined4 *)param_1[1];
          puVar4 = (undefined4 *)((((int)&local_3c - (int)puVar4) / 0x33) * 0x33 + *param_1);
          if (puVar5 != (undefined4 *)0x0) {
LAB_006aba94:
            for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
              *puVar5 = *puVar4;
              puVar4 = puVar4 + 1;
              puVar5 = puVar5 + 1;
            }
            *(undefined2 *)puVar5 = *(undefined2 *)puVar4;
            *(undefined1 *)((int)puVar5 + 2) = *(undefined1 *)((int)puVar4 + 2);
          }
        }
        else {
          if (puVar5 == (undefined4 *)param_1[2]) {
            FUN_006abc10();
          }
          puVar5 = (undefined4 *)param_1[1];
          if (puVar5 != (undefined4 *)0x0) {
            puVar4 = &local_3c;
            goto LAB_006aba94;
          }
        }
        param_1[1] = param_1[1] + 0x33;
        puVar3 = (undefined4 *)((int)puVar3 + 0x33);
        local_40 = local_40 - 1;
      } while (local_40 != 0);
    }
  }
switchD_006ab9c8_default:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

