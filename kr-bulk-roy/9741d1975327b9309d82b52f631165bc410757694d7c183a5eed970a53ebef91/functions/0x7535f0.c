
void FUN_007535f0(int param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5)

{
  tagPOINT local_28;
  tagRECT local_20;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_20.left = param_2;
  local_20.right = param_4;
  local_20.top = param_3;
  local_28.x = 0;
  local_28.y = 0;
  local_20.bottom = param_5;
  ClientToScreen(*(HWND *)(param_1 + 4),&local_28);
  OffsetRect(&local_20,local_28.x,local_28.y);
  ClipCursor(&local_20);
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

