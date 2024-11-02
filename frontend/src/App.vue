<template>
  <div id="app">
    <!-- nav bar -->
    <nav
      class="navbar navbar-light sticky-top border-bottom bg-dark"
      style="height: 10vh"
    ></nav>
    <router-view :key="$route.fullPath" />
    <footer class="bg-dark" style="height: 10vh"></footer>
  </div>
</template>

<script>
export default {
  data() {
    return {};
  },
  methods: {},
};
</script>
