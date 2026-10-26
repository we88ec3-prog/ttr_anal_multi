
void FUN_0044cf70(void)

{
  uint uVar1;
  int in_ECX;
  int local_cc;
  char *local_c8;
  undefined4 local_c4;
  char *local_c0;
  undefined4 local_bc;
  char *local_b8;
  undefined4 local_b4;
  char *local_b0;
  undefined4 local_ac;
  char *local_a8;
  undefined4 local_a4;
  char *local_a0;
  undefined4 local_9c;
  char *local_98;
  undefined4 local_94;
  char *local_90;
  undefined4 local_8c;
  char *local_88;
  undefined4 local_84;
  char *local_80;
  undefined4 local_7c;
  char *local_78;
  undefined4 local_74;
  char *local_70;
  undefined4 local_6c;
  char *local_68;
  undefined4 local_64;
  char *local_60;
  undefined4 local_5c;
  char *local_58;
  undefined4 local_54;
  char *local_50;
  undefined4 local_4c;
  char *local_48;
  undefined4 local_44;
  char *local_40;
  undefined4 local_3c;
  char *local_38;
  undefined4 local_34;
  char *local_30;
  undefined4 local_2c;
  char *local_28;
  undefined4 local_24;
  char *local_20;
  undefined4 local_1c;
  char *local_18;
  undefined4 local_14;
  char *local_10;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_cc = 0x40010005;
  local_c8 = "a Control-C";
  local_c4 = 0x40010008;
  local_c0 = "a Control-Break";
  local_bc = 0x80000002;
  local_b8 = "a Datatype Misalignment";
  local_b4 = 0x80000003;
  local_b0 = "a Breakpoint";
  local_ac = 0xc0000005;
  local_a8 = "an Access Violation";
  local_a4 = 0xc0000006;
  local_a0 = "an In Page Error";
  local_9c = 0xc0000017;
  local_98 = "a No Memory";
  local_94 = 0xc000001d;
  local_90 = "an Illegal Instruction";
  local_8c = 0xc0000025;
  local_88 = "a Noncontinuable Exception";
  local_84 = 0xc0000026;
  local_80 = "an Invalid Disposition";
  local_7c = 0xc000008c;
  local_78 = "a Array Bounds Exceeded";
  local_74 = 0xc000008d;
  local_70 = "a Float Denormal Operand";
  local_6c = 0xc000008e;
  local_68 = "a Float Divide by Zero";
  local_64 = 0xc000008f;
  local_60 = "a Float Inexact Result";
  local_5c = 0xc0000090;
  local_58 = "a Float Invalid Operation";
  local_54 = 0xc0000091;
  local_50 = "a Float Overflow";
  local_4c = 0xc0000092;
  local_48 = "a Float Stack Check";
  local_44 = 0xc0000093;
  local_40 = "a Float Underflow";
  local_3c = 0xc0000094;
  local_38 = "an Integer Divide by Zero";
  local_34 = 0xc0000095;
  local_30 = "an Integer Overflow";
  local_2c = 0xc0000096;
  local_28 = "a Privileged Instruction";
  local_24 = 0xc00000fd;
  local_20 = "a Stack Overflow";
  local_1c = 0xc0000142;
  local_18 = "a DLL Initialization Failed";
  local_14 = 0xe06d7363;
  local_10 = "a Microsoft C++ Exception";
  uVar1 = 0;
  do {
    if (in_ECX == (&local_cc)[uVar1 * 2]) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x18);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

