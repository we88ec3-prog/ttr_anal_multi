
void FUN_00748b00(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  uint uVar4;
  BOOL BVar5;
  int *in_ECX;
  undefined **local_44 [3];
  char *local_38;
  int local_34;
  undefined4 local_30;
  tagRECT local_28;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090a708;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar4;
  if (((uint)in_ECX[10] >> 8 & 1) != 0) {
    local_28.bottom = 0;
    local_28.right = 0;
    local_28.top = 0;
    local_28.left = 0;
    BVar5 = IntersectRect(&local_28,(RECT *)(in_ECX + 0xb),(RECT *)&stack0x00000008);
    if (BVar5 != 0) {
      local_30 = 0;
      local_34 = FUN_00891268(0x18,uVar4);
      if (local_34 == 0) {
        local_38 = (char *)0x0;
        std::exception::exception((exception *)local_44,&local_38);
        local_44[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_44,&DAT_00c857a8);
      }
      *(int *)local_34 = local_34;
      *(int *)(local_34 + 4) = local_34;
      local_8 = 0;
      cVar3 = (**(code **)(*in_ECX + 0x13c))
                        (param_1,local_28.left,local_28.top,local_28.right,local_28.bottom,&local_34
                        );
      if (cVar3 != '\0') {
        puVar1 = (undefined4 *)in_ECX[0x19];
        for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
          FUN_00748b00(&local_34,local_28.left,local_28.top,local_28.right,local_28.bottom);
        }
      }
      FUN_0056fb00();
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

