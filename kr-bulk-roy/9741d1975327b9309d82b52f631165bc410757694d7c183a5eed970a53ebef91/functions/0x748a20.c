
void FUN_00748a20(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  BOOL BVar3;
  int *in_ECX;
  tagRECT local_1c;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (((uint)in_ECX[10] >> 8 & 1) != 0) {
    local_1c.bottom = 0;
    local_1c.right = 0;
    local_1c.top = 0;
    local_1c.left = 0;
    BVar3 = IntersectRect(&local_1c,(RECT *)(in_ECX + 0xb),(RECT *)&stack0x00000010);
    if (BVar3 != 0) {
      (**(code **)(*in_ECX + 0x138))
                (param_1,param_2,*param_3,param_3[1],local_1c.left,local_1c.top,local_1c.right,
                 local_1c.bottom);
      puVar1 = (undefined4 *)in_ECX[0x19];
      for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
        FUN_00748a20(param_1,param_2,param_3,local_1c.left,local_1c.top,local_1c.right,
                     local_1c.bottom);
      }
    }
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

