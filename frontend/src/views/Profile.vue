<template>
  <div id="app">
    <hi>
      





      
    </hi>
  </div>
</template>

<script>
// @ is an alias to /src
export default {
  name: "Profile",
  data() {
    return {
      previousRoutes: [],
      search: "",
      center: {
        "d-flex": true,
        "justify-content-center": true,
        "align-items-center": true,
      },
    };
  },
  mounted() {},
  methods: {},
  watch: {
    $route(to, from) {
      this.previousRoutes.push(from); // เมื่อมีการเปลี่ยนเส้นทางใหม่ ให้เก็บเส้นทางก่อนหน้าลงในอาร์เรย์
    },
  },
};
</script>
